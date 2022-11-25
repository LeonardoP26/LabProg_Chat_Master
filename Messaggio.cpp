//
// Created by leona on 06/11/2022.
//


#include "Messaggio.h"


Messaggio::Messaggio(std::string s, std::string r, std::string mess, bool visual) : sender(s),
    receiver(r), text(mess), visual(visual)
{

}

const std::string &Messaggio::getText() const {
    return text;
}

void Messaggio::setText(const std::string &text) {
    Messaggio::text = text;
}

const std::string &Messaggio::getReceiver() const {
    return receiver;
}

void Messaggio::setReceiver(const std::string &receiver) {
    Messaggio::receiver = receiver;
}

const std::string &Messaggio::getSender() const {
    return sender;
}

void Messaggio::setSender(const std::string &sender) {
    Messaggio::sender = sender;
}

bool Messaggio::isVisual() const {
    return visual;
}

void Messaggio::setVisual(bool visual) {
    Messaggio::visual = visual;
}