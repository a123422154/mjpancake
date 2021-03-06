#ifndef P_GLOBAL_H
#define P_GLOBAL_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QQmlEngine>
#include <QColor>

class PGlobal : public QObject
{
    Q_OBJECT
public:
    explicit PGlobal(QObject *parent = 0);
    ~PGlobal();

    Q_PROPERTY(QString version READ version NOTIFY versionChanged)
    Q_PROPERTY(QVariant backColors READ backColors WRITE setBackColors NOTIFY backColorsChanged)
    Q_PROPERTY(QString savedUsername READ savedUsername WRITE setSavedUsername\
               NOTIFY savedUsernameChanged)
    Q_PROPERTY(bool savePassword READ savePassword WRITE setSavePassword NOTIFY savePasswordChanged)
    Q_PROPERTY(QString savedPassword READ savedPassword WRITE setSavedPassword\
               NOTIFY savedPasswordChanged)
    Q_PROPERTY(bool mute READ mute WRITE setMute NOTIFY muteChanged)
    Q_PROPERTY(QVariantMap hints READ hints WRITE setHints NOTIFY hintsChanged)

    Q_INVOKABLE void save();
    Q_INVOKABLE static void forceImmersive();
    Q_INVOKABLE static void systemNotify();

    static QString version();
    static QString configPath();
    static QString photoPath();
    static QString replayPath(QString filename = "");

    QVariant backColors() const;
    void setBackColors(const QVariant &v);

    QString savedUsername() const;
    void setSavedUsername(const QString &username);

    bool savePassword() const;
    void setSavePassword(bool v);
    QString savedPassword() const;
    void setSavedPassword(const QString &password);

    bool mute() const;
    void setMute(bool v);

    QVariantMap hints() const;
    void setHints(const QVariantMap &v);

signals:
    void versionChanged(); // placeholder
    void backColorsChanged();
    void savedUsernameChanged();
    void savePasswordChanged();
    void savedPasswordChanged();
    void muteChanged();
    void hintsChanged();

public slots:

private:
    void regulateRoot();

private:
    QJsonObject mRoot;
};

QObject *pGlobalSingletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine);

#endif // P_GLOBAL_H


