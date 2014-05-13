#include "haxeLexer.h"

#include <QDebug>

HaxeLexer::HaxeLexer(QTextDocument *document, QWidget *parent) :
    QWidget(parent),
    mDocument(document)
{
    buildTables();
}

void HaxeLexer::buildTables() {
    int tokenCount = 0;
    QString str;
    
    while (true) {
        mCurrentToken = getNextToken();
        
        if (mCurrentToken == END_OF_TOKEN_STREAM) {
            break;
        }
        
        switch (mCurrentToken) {
            //Create a string to represent the token
        }
        
        qDebug() << "Token:" << str << "Lexeme:" << getCurrentLexeme();
        
        ++tokenCount;
    }
    
    qDebug() << "Token count:" << tokenCount;
}

void HaxeLexer::reset() {
    
}

Token HaxeLexer::getNextToken() {
    mCurrentLexemeStart = mCurrentLexemeEnd;
    
    QString currentLineTxt = mDocument->findBlockByLineNumber(mCurrentLine).text();
    
    if (mCurrentLexemeStart >= currentLineTxt.length()) {
        if (!skipToNextLine()) {
            return END_OF_TOKEN_STREAM;
        }
    }
    
    mCurrentState = STATE_START;
    bool lexemeDone = false;
    
    char currentChar;
    int nextLexemeCharIndex = 0;
    bool addCurrentChar;
    
    while (true) {
        currentChar = getNextChar();
        
        if (currentChar == '\0') {
            break;
        }
        
        addCurrentChar = true;
        
        switch (mCurrentState) {
        case STATE_START: {
            if (isCharWhitespace(currentChar)) {
                ++mCurrentLexemeStart;
                addCurrentChar = false;
            } else if (isCharNumeric(currentChar)) {
                mCurrentState = STATE_INT;
            } else if (currentChar == '.') {
                mCurrentState = STATE_FLOAT;
            } else {
                //invalid
            }
            break;
        }
            
        case STATE_INT: {
            if (isCharNumeric(currentChar)) {
                mCurrentState = STATE_INT;
            } else if (currentChar == '.') {
                mCurrentState = STATE_FLOAT;
            } else if (isCharWhitespace(currentChar)) {
                addCurrentChar = false;
                lexemeDone = true;
            } else {
                //invalid
            }
            break;
        }
            
        case STATE_FLOAT: {
            if (isCharNumeric(currentChar)) {
                mCurrentState = STATE_FLOAT;
            } else if (isCharWhitespace(currentChar)) {
                addCurrentChar = false;
                lexemeDone = true;
            } else {
                //invalid
            }
        }
            
        }
        
        if (addCurrentChar) {
            mCurrentLexeme.append(currentChar);
            ++nextLexemeCharIndex;
        }
        
        if (lexemeDone)
            break;
        
        --mCurrentLexemeEnd;
    }
    
    switch (mCurrentState) {
    case STATE_INT:
        mCurrentToken = TOKEN_INT;
        break;
        
    case STATE_FLOAT:
        mCurrentToken = TOKEN_FLOAT;
        break;
        
    default:
        mCurrentToken = END_OF_TOKEN_STREAM;
    }
    
    return mCurrentToken;
    
    /*
    
    if (mCurrentState == STATE_END_STRING) {
        mCurrentState = STATE_NO_STRING;
    }
    
    if (mCurrentState != STATE_IN_STRING) {
        while (true) {
            if (!isCharWhitespace(currentLineTxt.at(mCurrentLexemeStart))) {
                break;
            }
            
            ++mCurrentLexemeStart;
        }
    }
    
    mCurrentLexemeEnd = mCurrentLexemeStart;
    
    while (true) {
        if (mCurrentState == STATE_IN_STRING) {
            if (mCurrentLexemeEnd >= currentLineTxt.length()) {
                mCurrentToken = TOKEN_INVALID;
                return mCurrentToken;
            }
            
            if (currentLineTxt.at(mCurrentLexemeEnd) == '\\') {
                mCurrentLexemeEnd += 2;
                continue;
            }
            
            if (currentLineTxt.at(mCurrentLexemeEnd) == '"') {
                break;
            }
            
            ++mCurrentLexemeEnd;
        } else {
            if (mCurrentLexemeEnd >= currentLineTxt.length()) {
                break;
            }
            
            if (isCharDelimiter(currentLineTxt.at(mCurrentLexemeEnd))) {
                break;
            }
            
            ++mCurrentLexemeEnd;
        }
    }
    
    if (mCurrentLexemeEnd - mCurrentLexemeStart == 0) {
        ++mCurrentLexemeEnd;
    }
    
    for (int i = mCurrentLexemeStart; i < mCurrentLexemeEnd; ++i) {
        if (mCurrentState == STATE_IN_STRING) {
            if (currentLineTxt.at(i) == '\\') {
                ++i;
            }
        }
        
        mCurrentLexeme.append(currentLineTxt.at(i));
    }
    
    mCurrentToken = TOKEN_INVALID;
    
    if (mCurrentLexeme.length() > 1 || mCurrentLexeme.at(0) != '"') {
        if (mCurrentState == STATE_IN_STRING) {
            mCurrentToken = TOKEN_STRING;
            return mCurrentToken;
        }
    }
    
    if (mCurrentLexeme.length() == 1) {
        switch (mCurrentLexeme.at(0).toLatin1()) {
        case '"':
        {
            switch (mCurrentState) {
            case STATE_NO_STRING:
                mCurrentState = STATE_IN_STRING;
                break;
            case STATE_IN_STRING:
                mCurrentState = STATE_END_STRING;
                break;
            default:
                break;
            }
            mCurrentToken = TOKEN_QUOTE;
            break;
        }
        case ',':
            mCurrentToken = TOKEN_COMMA;
            break;
        case ':':
            mCurrentToken = TOKEN_COLON;
            break;
        case '[':
            mCurrentToken = TOKEN_OPEN_BRACKET;
            break;
        case ']':
            mCurrentToken = TOKEN_CLOSE_BRACKET;
            break;
        case '{':
            mCurrentToken = TOKEN_OPEN_BRACE;
            break;
        case '}':
            mCurrentToken = TOKEN_CLOSE_BRACE;
            break;
        case '\n':
            mCurrentToken = TOKEN_NEWLINE;
            break;
        default:
            break;
        }
    }
    
    if (isStringInt(mCurrentLexeme)) {
        mCurrentToken = TOKEN_INT;
    }
    
    if (isStringFloat(mCurrentLexeme)) {
        mCurrentToken = TOKEN_FLOAT;
    }
    
    if (isStringIdentifier(mCurrentLexeme)) {
        mCurrentToken = TOKEN_IDENT;
    }
    
    if (mCurrentLexeme == "var") {
        mCurrentLexeme = TOKEN_VAR;
    }
    
    if (mCurrentLexeme == "function") {
        mCurrentLexeme = TOKEN_FUNC;
    }
    
    
    
    return mCurrentToken;
    */
}

char HaxeLexer::getNextChar() {
    return mDocument->findBlockByLineNumber(mCurrentLine).text().at(mCurrentLexemeEnd++).toLatin1();
}

QString HaxeLexer::getCurrentLexeme() {
    return mCurrentLexeme;
}

bool HaxeLexer::skipToNextLine() {
    ++mCurrentLine;
    
    if (mCurrentLine >= mDocument->blockCount()) {
        return false;
    }
    
    mCurrentLexemeStart = 0;
    mCurrentLexemeEnd = 0;
    
    mCurrentState = STATE_NO_STRING;
    
    return true;
}

bool HaxeLexer::isCharWhitespace(QChar c) {
    if (c == ' ' || c == '\t' || c == '\n') {
        return true;
    }
    
    return false;
}

bool HaxeLexer::isCharNumeric(QChar c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    
    return false;
}

bool HaxeLexer::isCharIdentifier(QChar c) {
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
         c == '_' ) {
        return true;
    }
    
    return false;
}

bool HaxeLexer::isCharDelimiter(QChar c) {
    if (c == ':' || c == ',' || c == '"' ||
        c == '[' || c == ']' ||
        c == '{' || c == '}' ||
        isCharWhitespace(c) || c == '\n') {
        return true;
    }
    
    return false;
}

bool HaxeLexer::isStringInt(QString str) {
    if (str.isEmpty()) {
        return false;
    }
    
    if (str.length() == 0) {
        return false;
    }
    
    int length = str.length();
    
    for (int i = 0; i < length; ++i) {
        if (!isCharNumeric(str.at(i)) && !(str.at(i) == '-')) {
            return false;
        }
    }
    
    for (int i = 1; i < length; ++i) {
        if (str.at(i) == '-') {
            return false;
        }
    }
    
    return true;
}

bool HaxeLexer::isStringFloat(QString str) {
    if (str.isEmpty()) {
        return false;
    }
    
    int length = str.length();
    bool radixPointFound = false;
    
    for (int i = 0; i < length; ++i) {
        if (!isCharNumeric(str.at(i)) && !(str.at(i) == '.') && !(str.at(i) == '-')) {
            return false;
        }
    }
    
    for (int i = 0; i < length; ++i) {
        if (str.at(i) == '.') {
            if (radixPointFound) {
                return false;
            }
            
            radixPointFound = true;
        }
    }
    
    for (int i = 1; i < length; ++i) {
        if (str.at(i) == '-') {
            return false;
        }
    }
    
    if (radixPointFound) {
        return true;
    }
    
    return false;
}

bool HaxeLexer::isStringIdentifier(QString str) {
    if (str.isEmpty()) {
        return false;
    }
    
    int length = str.length();
    
    for (int i = 0; i < length; ++i) {
        if (!isCharIdentifier(str.at(i))) {
            return false;
        }
    }
    
    return true;
}

bool HaxeLexer::isStringWhitespace(QString str) {
    if (str.isEmpty()) {
        return false;
    }
    
    int length = str.length();
    
    for (int i = 0; i < length; ++i) {
        if (!isCharWhitespace(str.at(i))) {
            return false;
        }
    }
    
    return true;
}
