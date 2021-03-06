#ifndef JSXPARSER_H
#define JSXPARSER_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QRegularExpression>

class JsxParser : public QThread
{
    Q_OBJECT
public:
    explicit JsxParser(QObject *parent = 0);

signals:
    void newTranslation(QStringList);
    void languageFound(QStringList);

    /**
     * @brief Signal emited when the parsing is over
     */
    void parsingFinished();

    /**
     * @brief Signal emited when the parsing has failed
     */
    void parsingFailed();

    void progress(int);

public slots:
    void parseFile(QFile *file);
    void parseText(QString *jsxinc);

protected:

    // Reimplemented from QThread
    void run();
private:

    /**
     * @brief The current text behing parsed
     */
    QString * currentText;

    /**
     * @brief Current file being parsed
     */
    QFile * currentFile;

    /**
     * @brief Parsing mode
     * 0 : nothing
     * 1 : Parse the current file
     * 2 : Parse the current string
     */
    int mode;

    void parseContent(QTextStream *jsxinc);
};

#endif // JSXPARSER_H
