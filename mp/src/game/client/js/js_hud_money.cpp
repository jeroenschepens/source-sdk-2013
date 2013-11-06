//   _____                                           _____ _      
//  / ____|                                         / ____(_)     
// | |     ___  _ __ ___  _ __   __ _ _ __  _   _  | (___  ___  __
// | |    / _ \| '_ ` _ \| '_ \ / _` | '_ \| | | |  \___ \| \ \/ /
// | |___| (_) | | | | | | |_) | (_| | | | | |_| |  ____) | |>  < 
//  \_____\___/|_| |_| |_| .__/ \__,_|_| |_|\__, | |_____/|_/_/\_\
//                       | |                 __/ |                
//                       |_|                |___/                 
//
// Programmed by Jeroen Schepens. Original code by Valve software
// c6_hud_money.cpp
// Company Six Money HUD item
// Purpose: Draws the amount of money that the players has on the screen

#include "cbase.h"
#include "c_hl2mp_player.h"
#include "hud.h"
#include "hudelement.h"
#include "hud_macros.h"
#include "hud_numericdisplay.h"
#include "iclientmode.h"

#include "vgui_controls/AnimationController.h"
#include "vgui/ILocalize.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#define INIT_BAT	-1

//-----------------------------------------------------------------------------
// Purpose: Displays suit power (armor) on hud
//-----------------------------------------------------------------------------
class CHudMoney : public CHudNumericDisplay, public CHudElement
{
	DECLARE_CLASS_SIMPLE( CHudMoney, CHudNumericDisplay );

public:
	CHudMoney( const char *pElementName );
	void Init( void );
	void Reset( void );
	void VidInit( void );
	void OnThink( void );
};

DECLARE_HUDELEMENT( CHudMoney );

//-----------------------------------------------------------------------------
// Purpose: Constructor
//-----------------------------------------------------------------------------
CHudMoney::CHudMoney( const char *pElementName ) : BaseClass(NULL, "HudMoney"), CHudElement( pElementName )
{
	SetHiddenBits( HIDEHUD_HEALTH | HIDEHUD_NEEDSUIT );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudMoney::Init( void )
{
	Reset();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudMoney::Reset( void )
{
	wchar_t *tempString = g_pVGuiLocalize->Find("#Hud_Level");

	if (tempString)
	{
		SetLabelText(tempString);
	}
	else
	{
		SetLabelText(L"Money");
	}
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudMoney::VidInit( void )
{
	Reset();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudMoney::OnThink( void )
{
	C_HL2MP_Player *pPlayer = C_HL2MP_Player::GetLocalHL2MPPlayer();
	if ( pPlayer )
		SetDisplayValue(pPlayer->GetMoney());

	switch( pPlayer->GetTeamNumber() )
	{
#if defined ( SDK_USE_TEAMS )
	case SDK_TEAM_BLUE:
		{
			BaseClass::SetFgColor(Color(0, 127, 255, 255));
			BaseClass::SetBgColor(Color(0, 63, 128, 200));
		}
		break;
	case SDK_TEAM_RED:
		{
			BaseClass::SetFgColor(Color(255, 0, 0, 255));
			BaseClass::SetBgColor(Color(128, 0, 0, 200));
		}		
		break;
#endif
	default:
		{

		}
		break;		
	}

}
