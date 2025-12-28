#pragma once
#include <string>
#include"Message.h"
#include<iostream>
 using namespace std;

 class VoiceMessage : public Message
 {
    void drawWave(ostream& out, int stars) const {
        out << "|";
        for (int i = 0; i < stars; ++i)
            out << "*";
        out << endl;
    }
    public:
    VoiceMessage(long int senderId, const string& sentAt)
        : Message(senderId, sentAt) {}

    string getType() const override {
        return "VOICE";
    }

    void saveas4File(ostream& out, int stars) const {
        out << "[VOICE] "<< "Sender:" << senderId<< " Time:" << sentAt << endl;
        drawWave(out, stars);
    }

    void print(int stars) const {
        cout << "Voice Message from " << senderId<< " at " << sentAt << endl;
        drawWave(cout, stars);
    }

    void saveasFile(ostream& out) const override {
        drawWave(out, 5);
    }

    void print() const override {
        drawWave(cout, 5);
    }
 };