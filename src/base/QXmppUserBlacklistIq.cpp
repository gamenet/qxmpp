#include "QXmppUserBlacklistIq.h"
#include "QXmppConstants.h"
#include "QXmppUtils.h"

QXmppUserBlacklistIq::QXmppUserBlacklistIq()
{
}

QXmppUserBlacklistIq::~QXmppUserBlacklistIq()
{
}

QStringList QXmppUserBlacklistIq::blocklist()
{
  return m_items;
}

bool QXmppUserBlacklistIq::isUserBlacklistIq(const QDomElement &element)
{
  QDomElement blacklistElenent = element.firstChildElement("blocklist");
  return (blacklistElenent.namespaceURI() == ns_blocking);
}

void QXmppUserBlacklistIq::parseElementFromChild(const QDomElement &element)
{
  QDomElement itemElement = element
    .firstChildElement("blocklist")
    .firstChildElement("item");

  while (!itemElement.isNull()) {
    this->m_items.append(itemElement.attribute("jid"));
    itemElement = itemElement.nextSiblingElement();
  }
}

void QXmppUserBlacklistIq::toXmlElementFromChild(QXmlStreamWriter *writer) const
{
  writer->writeStartElement("blocklist");
  writer->writeAttribute("xmlns", ns_blocking);
  writer->writeEndElement();
}

QXmppUserBlacklistBlockIq::QXmppUserBlacklistBlockIq()
{

}

QXmppUserBlacklistBlockIq::~QXmppUserBlacklistBlockIq()
{

}

QString QXmppUserBlacklistBlockIq::jid() const
{
  return this->m_jid;
}

void QXmppUserBlacklistBlockIq::setJid(const QString& value)
{
  this->m_jid = value;
}

bool QXmppUserBlacklistBlockIq::isUserBlacklistBlockIq(const QDomElement &element)
{
  QDomElement blacklistBlockElenent = element.firstChildElement("block");
  return (blacklistBlockElenent.namespaceURI() == ns_blocking);
}

void QXmppUserBlacklistBlockIq::parseElementFromChild(const QDomElement &element)
{
  QDomElement blockElement = element
    .firstChildElement("block")
    .firstChildElement("item");
  
  this->m_jid = blockElement.attribute("jid");
}

void QXmppUserBlacklistBlockIq::toXmlElementFromChild(QXmlStreamWriter *writer) const
{
  writer->writeStartElement("block");
  writer->writeAttribute("xmlns", ns_blocking);
  
  writer->writeStartElement("item");
  helperToXmlAddAttribute(writer, "jid", m_jid);
  writer->writeEndElement();

  writer->writeEndElement();
}

QXmppUserBlacklistUnblockIq::QXmppUserBlacklistUnblockIq()
{

}

QXmppUserBlacklistUnblockIq::~QXmppUserBlacklistUnblockIq()
{

}

QString QXmppUserBlacklistUnblockIq::jid() const
{
  return this->m_jid;
}

void QXmppUserBlacklistUnblockIq::setJid(const QString& value)
{
  this->m_jid = value;
}

bool QXmppUserBlacklistUnblockIq::isUserBlacklistUnblockIq(const QDomElement &element)
{
  QDomElement blacklistUnblockElenent = element.firstChildElement("unblock");
  return (blacklistUnblockElenent.namespaceURI() == ns_blocking);
}

void QXmppUserBlacklistUnblockIq::parseElementFromChild(const QDomElement &element)
{
  QDomElement blockElement = element
    .firstChildElement("unblock")
    .firstChildElement("item");

  this->m_jid = blockElement.attribute("jid");
}

void QXmppUserBlacklistUnblockIq::toXmlElementFromChild(QXmlStreamWriter *writer) const
{
  writer->writeStartElement("unblock");
  writer->writeAttribute("xmlns", ns_blocking);

  writer->writeStartElement("item");
  helperToXmlAddAttribute(writer, "jid", m_jid);
  writer->writeEndElement();

  writer->writeEndElement();
}
