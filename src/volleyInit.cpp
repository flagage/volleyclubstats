#include "volleyInit.h"

namespace VolleyStats
{
    Valeur::Valeur()
    {
        _ListValeur<<"++"<<"+"<<"0"<<"-"<<"--"<<"tot"<<"eff1"<<"eff2"<<"eff3"<<"eff4";
    }
    Valeur::~Valeur()
    {
        _ListValeur.clear();
    }

    int Valeur::GetSizeValeur()
    {
        return _ListValeur.size();
    }
    QString Valeur::GetElementValeur(int valu)
    {
        switch (valu)
        {
        case VPP:
            return "++";
            break;
        case VP:
            return "+";
            break;
        case V0:
            return "0";
            break;
        case VM:
            return "-";
            break;
        case VMM:
            return "--";
            break;
        case TOT:
            return "tot";
            break;
        case EFF1:
            return "eff1";
            break;
        case EFF2:
            return "eff2";
            break;
        case EFF3:
            return "eff3";
            break;
        case EFF4:
            return "eff4";
            break;
        }
    }

    /*Action::Action()
    {
        _ListAction<<"Service"<<"Récéption"<<"Contre"<<"Défense"<<"Passe"<<"Attaque";
    }
    Action::~Action()
    {
        _ListAction.clear();
    }
    int Action::GetSizeAction()
    {
        return _ListAction.size();
    }

    QString Action::GetElementAction(int action)
    {
        switch (action)
        {
        case SERV:
            return _ListAction.at(0);
            break;
        case RECEP:
            return _ListAction.at(1);
            break;
        case CONTRE:
            return _ListAction.at(2);
            break;
        case PASSE:
            return _ListAction.at(4);
            break;
        case DEF:
            return _ListAction.at(3);
            break;
        case ATTA:
            return _ListAction.at(5);
            break;
        }
    }*/
    /*QStringList GetMAction()
    {
        return m_ListAction;
    }*/
}
