#ifndef QSPLOGGER_H
#define QSPLOGGER_H

//#include <QDateTime>
//#include <QFileInfo>
//#include <QObject>
//#include <QString>
#include <log4cplus/appender.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/spi/loggingevent.h>
#include <log4cplus/tstring.h>

class LOG4CPLUS_EXPORT QspLogger : public log4cplus::Appender
{
    //Q_OBJECT
public:
    QspLogger();
    ~QspLogger() {};

//signals:
//    void logMessageReceived(const QString &message);

protected:
    void append(const log4cplus::spi::InternalLoggingEvent &even) override;

    void close() override;

    virtual log4cplus::tstring getName() override;

    virtual void setName(const log4cplus::tstring &name) override;

private:
    //QString toQString(const log4cplus::tstring &tstring);
    //
    //QString getLevelAndColor(const log4cplus::LogLevel &level);

    //QString m_strColor = "red";

    log4cplus::tstring m_strName;
};


#define LOG_TRACE(logEvent) LOG4CPLUS_TRACE(logger, logEvent)
#define LOG_DEBUG(logEvent) LOG4CPLUS_DEBUG(logger, logEvent)
#define LOG_DEBUG_F(...) LOG4CPLUS_DEBUG_FMT(logger, __VA_ARGS__)
#define LOG_INFO(logEvent) LOG4CPLUS_INFO(logger, logEvent)
#define LOG_WARN(logEvent) LOG4CPLUS_WARN(logger, logEvent)
#define LOG_ERROR(logEvent) LOG4CPLUS_ERROR(logger, logEvent)
#define LOG_FATAL(logEvent) LOG4CPLUS_FATAL(logger, logEvent)


#endif//QSPLOGGER_H