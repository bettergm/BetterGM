#ifndef HAXELEXER_H
#define HAXELEXER_H

#include <QWidget>
#include <QTextDocument>
#include <QTextBlock>
#include <QMap>

typedef int Token;

class HaxeLexer : public QWidget {
    Q_OBJECT
    
public:
    HaxeLexer(QTextDocument *document, QWidget *parent = 0);
    
    enum LexState {
        STATE_START,
        STATE_NO_STRING,
        STATE_IN_STRING,
        STATE_END_STRING,
        STATE_INT,
        STATE_FLOAT
    };
    
    enum Tokens {
        TOKEN_INT,
        TOKEN_FLOAT,
        TOKEN_STRING,
        TOKEN_BOOL,
        TOKEN_DYNAMIC,
        TOKEN_IDENT,
        TOKEN_COLON,
        TOKEN_OPEN_BRACKET,
        TOKEN_CLOSE_BRACKET,
        TOKEN_QUOTE,
        TOKEN_COMMA,
        TOKEN_OPEN_BRACE,
        TOKEN_CLOSE_BRACE,
        TOKEN_NEWLINE,
        
        TOKEN_VAR,
        TOKEN_PARAM,
        TOKEN_FUNC,
        
        TOKEN_INVALID,
        END_OF_TOKEN_STREAM
    };
    
    void buildTables();
    
    void reset();
    
    Token getNextToken();
    QString getCurrentLexeme();
    
private:
    bool skipToNextLine();
    bool isCharWhitespace(QChar c);
    bool isCharNumeric(QChar c);
    bool isCharIdentifier(QChar c);
    bool isCharDelimiter(QChar c);
    
    bool isStringInt(QString str);
    bool isStringFloat(QString str);
    bool isStringIdentifier(QString str);
    bool isStringWhitespace(QString str);
    
    char getNextChar();
    
    QTextDocument *mDocument;
    
    int mCurrentLine;
    int mCurrentState;
    int mCurrentLexemeStart;
    int mCurrentLexemeEnd;
    
    Token mCurrentToken;
    QString mCurrentLexeme;
    
    //The tables
    QMap<QString, int> mFunctionTable;
    QMap<QString, int> mMemberVariableTable;
    QMap<QString, int> mPublicVariableTable;
    QMap<QString, int> mLocalVariableTable;
    QMap<QString, int> mClassTable;
};

#endif // HAXELEXER_H
