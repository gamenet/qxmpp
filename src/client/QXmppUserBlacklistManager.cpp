#include "QXmppUserBlacklistManager.h"
#include "QXmppUserBlacklistIq.h"
#include "QXmppClient.h"
#include "QXmppConstants.h"

QXmppUserBlacklistManager::QXmppUserBlacklistManager()
{
}


QXmppUserBlacklistManager::~QXmppUserBlacklistManager()
{
}

void QXmppUserBlacklistManager::requestList()
{
  QXmppUserBlacklistIq blockListIq;
  blockListIq.setType(QXmppIq::Get);
  blockListIq.setFrom(client()->configuration().jid());
  client()->sendPacket(blockListIq);
}

void QXmppUserBlacklistManager::blockUser(const QString& bareJid)
{
  QXmppUserBlacklistBlockIq blockIq;
  blockIq.setType(QXmppIq::Set);
  blockIq.setJid(bareJid);
  client()->sendPacket(blockIq);
}

void QXmppUserBlacklistManager::unblockUser(const QString& bareJid)
{
  QXmppUserBlacklistUnblockIq unblockIq;
  unblockIq.setType(QXmppIq::Set);
  unblockIq.setJid(bareJid);
  client()->sendPacket(unblockIq);
}

QStringList QXmppUserBlacklistManager::discoveryFeatures() const
{
  // XEP-0191: Blocking Command
  return QStringList() << ns_blocking;
}

bool QXmppUserBlacklistManager::handleStanza(const QDomElement &element)
{
  if (element.tagName() != "iq")
    return false;
    
  // XEP-0191: Blocking Command
  if (QXmppUserBlacklistIq::isUserBlacklistIq(element))
  {
    QXmppUserBlacklistIq blockListIq;
    blockListIq.parse(element);
    emit blacklistReceived(blockListIq.blocklist());
    return true;
  } else if (QXmppUserBlacklistBlockIq::isUserBlacklistBlockIq(element))
  {
    QXmppUserBlacklistBlockIq blockIq;
    blockIq.parse(element);
    emit blocked(blockIq.jid());
    return true;
  } else if (QXmppUserBlacklistUnblockIq::isUserBlacklistUnblockIq(element))
  {
    QXmppUserBlacklistUnblockIq unblockIq;
    unblockIq.parse(element);
    emit unblocked(unblockIq.jid());
    return true;
  }

  return false;
}
