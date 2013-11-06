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
// c6_buyable.h
// Company Six Buyable Interface - Server - Header
// Purpose: Interface for buyable items

#include "items.h"
#include "js/js_item_defs.h"

#ifndef C6_ITEM_DEFS_H
#define C6_ITEM_DEFS_H
#ifdef _WIN32
#pragma once
#endif

class CBuyableItem : public CItem
{
public:
	DECLARE_CLASS( CBuyableItem, CItem );
	void SetPrice(int price)//Set the item's price
	{
		m_iPrice = price;
	}
	int GetPrice (void)//Get the item's price
	{
		return m_iPrice;
	}
	void SetType(int type)//Set the item's type
	{
		m_iType = type;
	}
	int GetType (void)//Get the item's type
	{
		return m_iType;
	}
private:
	int m_iPrice;//The item's price
	int m_iType;// The item's type
};

#endif
