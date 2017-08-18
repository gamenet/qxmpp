#ifndef QXMPPUSERBLACKLISTIQ_H
#define QXMPPUSERBLACKLISTIQ_H

#include "QXmppIq.h"
#include <QDomElement>

class QXMPP_EXPORT QXmppUserBlacklistIq : public QXmppIq
{
public:
  QXmppUserBlacklistIq();
  ~QXmppUserBlacklistIq();

  QStringList blocklist();

  /// \cond
  static bool isUserBlacklistIq(const QDomElement &element);

protected:
  void parseElementFromChild(const QDomElement &element);
  void toXmlElementFromChild(QXmlStreamWriter *writer) const;

  /// \endcond

private:
  QStringList m_items;
};

class QXMPP_EXPORT QXmppUserBlacklistBlockIq : public QXmppIq
{
public:
  QXmppUserBlacklistBlockIq();
  ~QXmppUserBlacklistBlockIq();

  QString jid() const;
  void setJid(const QString& value);

  /// \cond
  static bool isUserBlacklistBlockIq(const QDomElement &element);

protected:
  void parseElementFromChild(const QDomElement &element);
  void toXmlElementFromChild(QXmlStreamWriter *writer) const;
  /// \endcond

private:
  QString m_jid;
};

class QXMPP_EXPORT QXmppUserBlacklistUnblockIq : public QXmppIq
{
public:
  QXmppUserBlacklistUnblockIq();
  ~QXmppUserBlacklistUnblockIq();

  QString jid() const;
  void setJid(const QString& value);

  /// \cond
  static bool isUserBlacklistUnblockIq(const QDomElement &element);

protected:
  void parseElementFromChild(const QDomElement &element);
  void toXmlElementFromChild(QXmlStreamWriter *writer) const;

  /// \endcond

private:
  QString m_jid;
};

#endif