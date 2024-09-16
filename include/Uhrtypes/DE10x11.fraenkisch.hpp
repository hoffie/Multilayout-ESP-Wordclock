#pragma once

#include "Uhrtype.hpp"

/*
 *           Layout Front
 *                COL
 *       X 9 8 7 6 5 4 3 2 1 0
 * ROW + - - - - - - - - - - -
 *  0  | E S A U I S B A S S D
 *  1  | A F E I A D E S C H O
 *  2  | G L E I C H N O O C H
 *  3  | B D R E I V Ä D D L M
 *  4  | H A L B Ä Y Z E H N A
 *  5  | F Ü N F A Z W A A N S
 *  6  | E L F A Q S I E M A R
 *  7  | O C H D A N E U N A M
 *  8  | S E C H S A V I E R A
 *  9  | Z W Ö L F A D R E I A
 */

class De10x11fraenkisch_t : public iUhrType {
public:
    virtual LanguageAbbreviation usedLang() override {
        return LanguageAbbreviation::DE;
    };

    //------------------------------------------------------------------------------

    virtual const bool hasFive() override { return true; }
    virtual const bool hasZwanzig() override { return true; }
    virtual const bool hasTwentyfive() override { return true; }
    virtual const bool hasThirtyfive() override { return true; }
    virtual const bool hasForty() override { return true; }
    virtual const bool hasDreiviertel() override { return true; }
    virtual const bool hasFifty() override { return true; }
    virtual const bool hasFiftyFive() override { return true; }
    virtual const int getOffsetHour(uint8_t minutes) override {
        if (minutes <= 5) {
            return 0;
        }
        return 1;
    }

    //------------------------------------------------------------------------------

    void show(FrontWord word) override {
        switch (word) {

        case FrontWord::es_ist:
            setFrontMatrixWord(0, 9, 10); // Es
            setFrontMatrixWord(0, 5, 6);  // is
            setFrontMatrixWord(1, 7, 9);  // fei
            setFrontMatrixWord(1, 0, 3);  // scho
            break;

        case FrontWord::min_5:
            setFrontMatrixWord(2, 0, 4); // nooch
            break;

        case FrontWord::min_10:
            setFrontMatrixWord(2, 5, 10); // gleich
            setFrontMatrixWord(3, 1, 5);  // väddel
            break;

        case FrontWord::viertel:
            setFrontMatrixWord(3, 1, 5); // väddel
            break;

        case FrontWord::min_20:
            setFrontMatrixWord(2, 0, 4); // nooch
            setFrontMatrixWord(3, 1, 5); // väddel
            break;

        case FrontWord::min_25:
            setFrontMatrixWord(2, 5, 10); // gleich
            setFrontMatrixWord(4, 6, 10); // halbä
            break;

        case FrontWord::halb:
            setFrontMatrixWord(4, 6, 10); // halbä
            break;

        case FrontWord::min_35:
            setFrontMatrixWord(2, 0, 4); // nooch
            setFrontMatrixWord(4, 6, 10); // halbä
            break;

        case FrontWord::min_40:
            setFrontMatrixWord(2, 5, 10); // gleich
            setFrontMatrixWord(3, 1, 9);  // dreiväddel
            break;

        case FrontWord::dreiviertel:
            setFrontMatrixWord(3, 1, 9); // dreiväddel
            break;

        case FrontWord::min_50:
            setFrontMatrixWord(2, 0, 4); // nooch
            setFrontMatrixWord(3, 1, 9); // dreiväddel
            break;

        case FrontWord::min_55:
            setFrontMatrixWord(2, 5, 10); // gleich
            break;

        case FrontWord::eins:
        case FrontWord::hour_1:
            setFrontMatrixWord(5, 0, 3);
            break;

        case FrontWord::hour_2:
            setFrontMatrixWord(5, 2, 5);
            break;

        case FrontWord::hour_3:
            setFrontMatrixWord(9, 0, 4);
            break;

        case FrontWord::hour_4:
            setFrontMatrixWord(8, 0, 4);
            break;

        case FrontWord::hour_5:
            setFrontMatrixWord(5, 6, 10);
            break;

        case FrontWord::hour_6:
            setFrontMatrixWord(8, 5, 10);
            break;

        case FrontWord::hour_7:
            setFrontMatrixWord(6, 1, 5);
            break;

        case FrontWord::hour_8:
            setFrontMatrixWord(7, 6, 10);
            break;

        case FrontWord::hour_9:
            setFrontMatrixWord(7, 1, 5);
            break;

        case FrontWord::hour_10:
            setFrontMatrixWord(4, 0, 4);
            break;

        case FrontWord::hour_11:
            setFrontMatrixWord(6, 7, 10);
            break;

        case FrontWord::hour_12:
            setFrontMatrixWord(9, 5, 10);
            break;

        default:
            break;
        };
    };
};

De10x11fraenkisch_t _de10x11fraenkisch;