#include "volleyInit.h"


InitValeur* InitValeur::_InstanceValeur = NULL;

InitValeur::InitValeur()
{
    _ListValeur<<"++"<<"+"<<"0"<<"-"<<"--"<<"tot"<<"eff1"<<"eff2"<<"eff3"<<"eff4";
    //_InstanceValeur=NULL;
}

InitValeur::~InitValeur()
{
    _ListValeur.clear();
}

QStringList InitValeur::GetListValeur()
{
    return _ListValeur;
}
InitValeur* InitValeur::GetInstance()
{
    return _InstanceValeur;
}

InitValeur* InitValeur::donneInstance()
{
     if(_InstanceValeur == NULL)
        {
            _InstanceValeur=new InitValeur();
        }
        return _InstanceValeur;
}

void InitValeur::libereInstance()
{
     if(_InstanceValeur!=NULL)
        {
            delete _InstanceValeur;
            _InstanceValeur=NULL;
        }
}
int InitValeur::GetSizeValeur()
{
    return _ListValeur.size();
}
QString InitValeur::GetElementValeur(int valu)
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

