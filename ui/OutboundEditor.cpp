#include "OutboundEditor.hpp"

OutboundEditor::OutboundEditor(QWidget *parent) : Qv2rayPlugin::QvPluginEditor(parent)
{
    setupUi(this);
}

void OutboundEditor::SetContent(const QJsonObject &r)
{
    root = r;
    const auto protocol = root["protocol"].toString();

    textUsername->setText(root["username"].toString());
    textPassword->setText(root["password"].toString());
    comboProtocol->setCurrentText(protocol != "https" && protocol != "quic" ? "https" : root["protocol"].toString());
}

void OutboundEditor::changeEvent(QEvent *e)
{

    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange: retranslateUi(this); break;
        default: break;
    }
}

void OutboundEditor::on_comboProtocol_currentTextChanged(const QString &arg1)
{
    root["protocol"] = arg1;
}

void OutboundEditor::on_textUsername_textEdited(const QString &arg1)
{
    root["username"] = arg1;
}

void OutboundEditor::on_textPassword_textEdited(const QString &arg1)
{
    root["password"] = arg1;
}
