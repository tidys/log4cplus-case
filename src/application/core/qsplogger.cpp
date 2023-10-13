#include "qsplogger.h"

QspLogger::QspLogger()
{
}

void QspLogger::close()
{
}

void QspLogger::append(const log4cplus::spi::InternalLoggingEvent &even)
{
    log4cplus::tstring logMessage = even.getMessage();
    log4cplus::tstring logName = even.getLoggerName();
    log4cplus::LogLevel logLevel = even.getLogLevel();
    log4cplus::tstring logThread = even.getThread();
    //log4cplus::tstring logFile = even.getFile();
    //log4cplus::tstring logFunction = even.getFunction();
    //int logLine = even.getLine();
    /*QString strLevel;
    if (logLevel == log4cplus::ERROR_LOG_LEVEL)
    {
        strLevel = "[ERROR]";
    }
    else
    {
        strLevel = "[INFO ]";
    }

    QString strFile = toQString(logFile);
    QFileInfo fileInfo(strFile);
    QString fileName = fileInfo.fileName();
    QDateTime currentDateTime = QDateTime::currentDateTime();

    QString strMessage = currentDateTime.toString("yyyy-MM-dd HH:mm:ss") + " " + toQString(logThread) + " " + strLevel + " " + toQString(logName) + " " + fileName + " " + toQString(logFunction) + " " + QString::number(logLine) + " " + toQString(logMessage);


    QString str;
    if (logLevel == log4cplus::ERROR_LOG_LEVEL)
    {
        str = QString("<font color = %1> %2 </font>").arg(m_strColor).arg(strMessage);
    }
    else
    {
        str = strMessage;
    }


    emit logMessageReceived(str);*/
}

log4cplus::tstring QspLogger::getName()
{
    return m_strName;
}

void QspLogger::setName(const log4cplus::tstring &name)
{
    m_strName = name;
}



//QString QspLogger::toQString(const log4cplus::tstring &tstring)
//{
//    return QString::fromStdString(log4cplus::helpers::tostring(tstring));
//}
//
//
//QString QspLogger::getLevelAndColor(const log4cplus::LogLevel &level)
//{
//    QString strLevel;
//    switch (level)
//    {
//        case log4cplus::DEBUG_LOG_LEVEL:
//            strLevel = "[DEBUG]";
//            m_strColor = "blue";
//            break;
//        case log4cplus::INFO_LOG_LEVEL:
//            strLevel = "[INFO ]";
//            m_strColor = "black";
//            break;
//        case log4cplus::WARN_LOG_LEVEL:
//            strLevel = "[WARN ]";
//            break;
//        case log4cplus::ERROR_LOG_LEVEL:
//            strLevel = "[ERROR]";
//            break;
//        default:
//            break;
//    }
//    return strLevel;
//}