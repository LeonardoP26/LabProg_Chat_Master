//
// Created by leona on 06/11/2022.
//

#ifndef LABPROG_CHAT_MASTER_MESSAGGIO_H
#define LABPROG_CHAT_MASTER_MESSAGGIO_H


#include <string>
#include <ctime>

class Messaggio {
public:
    Messaggio(std::string s, std::string r, std::string mess, bool visual = false);

    //Metodi che servono per test
    const std::string &getText() const;

    void setText(const std::string &text);

    const std::string &getReceiver() const;

    void setReceiver(const std::string &receiver);

    const std::string &getSender() const;

    void setSender(const std::string &sender);

    bool isVisual() const;

    void setVisual(bool visual);


    bool operator==(const Messaggio &mc) const;
    bool operator!=(const Messaggio &mc) const;

private:
    std::string sender;
    std::string receiver;
    std::string text;
    bool visual;
};




#endif //LABPROG_CHAT_MASTER_MESSAGGIO_H
