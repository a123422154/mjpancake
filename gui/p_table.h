#ifndef P_TABLE_H
#define P_TABLE_H

#include "gui/p_table_local.h"
#include "gui/p_client.h"

#include <QObject>
#include <QThread>

class PTable : public QObject
{
    Q_OBJECT
public:
    explicit PTable(QObject *parent = 0);
    ~PTable();

    Q_INVOKABLE void startLocal(const QVariant &girlIds, const QVariant &gameRule,
                                int tempDealer);
    Q_INVOKABLE void startOnline(PClient *client);
    Q_INVOKABLE void startSample();

signals:
    void action(int who, QString actStr, int index = -1);
    void saveRecord();

    void firstDealerChoosen(int dealer);
    void roundStarted(int round, int extra, int dealer, bool allLast, int deposit);
    void cleaned();
    void diced(int die1, int die2);
    void dealt(const QVariant &inits);
    void flipped(const QVariant &newIndic);
    void activated(const QVariant &action, int lastDiscarder);
    void drawn(int who, const QVariant &tile, bool rinshan);
    void discarded(int who, const QVariant &tile,
                   int outPos, int inPos);
    void riichied(int who);
    void riichiPassed(int who);
    void barked(int who, int fromWhom, QString actStr,
                int index, int index2, const QVariant &bark);
    void roundEnded(QString result, const QVariant &openers, int gunner,
                    const QVariant &forms, const QVariant &uraIndics);
    void pointsChanged(const QVariant &points);
    void tableEnded(const QVariant &rank, const QVariant &scores);
    void poppedUp(int who, QString str);
    void justPause(int ms);

public slots:

private:
    QThread workThread;
};

#endif // P_TABLE_H