#include "volleyInit.h"


InitValeur* InitValeur::_InstanceValeur = NULL;

InitValeur::InitValeur()
{
    _ListValeur<<"PP"<<"P"<<"0"<<"M"<<"MM"<<"tot";

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
        return "PP";
        break;
    case VP:
        return "P";
        break;
    case V0:
        return "0";
        break;
    case VM:
        return "M";
        break;
    case VMM:
        return "MM";
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
void InitValeur::SetSelection(QStringList list)
{
     for(int i=0;i<list.size();i++)
    {
        this->_ListValeur.append(list.at(i));
    }

}



InitAction* InitAction::_InstanceAction = NULL;

InitAction::InitAction()
{
   _ListAction<<("Service")<<("Récéption")<<("Contre")<<("Défense")<<("Passe")<<("Attaque");
}

InitAction::~InitAction()
{
    _ListAction.clear();
}

QStringList InitAction::GetListAction()
{
    return _ListAction;
}
InitAction* InitAction::GetInstance()
{
    return _InstanceAction;
}

InitAction* InitAction::donneInstance()
{
     if(_InstanceAction == NULL)
        {
            _InstanceAction=new InitAction();
        }
        return _InstanceAction;
}

void InitAction::libereInstance()
{
     if(_InstanceAction!=NULL)
        {
            delete _InstanceAction;
            _InstanceAction=NULL;
        }
}
int InitAction::GetSizeAction()
{
    return _ListAction.size();
}
QString InitAction::GetElementAction(int valu)
{
    QString strretour;
    switch (valu)
    {
    case  SERV:
        strretour="Service";
        break;
    case RECEP:
        strretour="Reception";
        break;
    case CONTRE:
        strretour="Contre";
        break;
    case DEF:
        strretour="Defense";
        break;
    case PASSE:
        strretour="Passe";
        break;
    case ATTA:
        strretour="Attaque";
        break;
    }
    return strretour;
}
void InitAction::SetSelection(QStringList list)
{
    for(int i=0;i<list.size();i++)
    {
        this->_ListAction.append(list.at(i));
    }

}

InitGlobal* InitGlobal::_InstanceGlobal = NULL;

InitGlobal::InitGlobal()
{
    _nbSet=5;
    _nbJoueur=6;
}
InitGlobal::~InitGlobal()
{

}

InitGlobal* InitGlobal::GetInstance()
{
    return _InstanceGlobal;
}

InitGlobal* InitGlobal::donneInstance()
{
     if(_InstanceGlobal == NULL)
        {
            _InstanceGlobal=new InitGlobal();
        }
        return _InstanceGlobal;
}

void InitGlobal::libereInstance()
{
     if(_InstanceGlobal!=NULL)
        {
            delete _InstanceGlobal;
            _InstanceGlobal=NULL;
        }
}

int InitGlobal::GetNbSet()
{
    return this->_nbSet;
}
void InitGlobal::SetNbSet(int nbSet)
{
    this->_nbSet=nbSet;
}

int InitGlobal::GetNbJoueur()
{
    return this->_nbJoueur;
}

void InitGlobal::SetNbJoueur(int nbJoueur)
{
    this->_nbJoueur=nbJoueur;
}
