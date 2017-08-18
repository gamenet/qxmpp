#ifndef QXMPPBLACKLISTMANAGER_H
#define QXMPPBLACKLISTMANAGER_H

#include "QXmppClientExtension.h"

#include <QtCore/QString>
#include <QtCore/QStringList>

class QXMPP_EXPORT QXmppUserBlacklistManager : public QXmppClientExtension
{
  Q_OBJECT
public:
  QXmppUserBlacklistManager();
  ~QXmppUserBlacklistManager();

  void requestList();
  void blockUser(const QString& bareJid);
  void unblockUser(const QString& bareJid);

  /// \cond
  virtual QStringList discoveryFeatures() const override;
  virtual bool handleStanza(const QDomElement &stanza) override;
  /// \endcond

signals:
  void blacklistReceived(QStringList blacklist);
  void blocked(QString jid);
  void unblocked(QString jid);
};

#endif