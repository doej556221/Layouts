
/**
 * \file Layouts.cpp
 * \~english @brief File for project functions
 * \~english @details
 * This file contains implementation of project functions
 * \~russian @brief Файл функций проекта
 * \~russian @details
 * Этот файл содержит реализацию функций проекта
 */

#include "pch.h"
#include "framework.h"
#include "Layouts.h"

CLayouts::CLayouts()
{

}

int CLayouts::GetVersion()
{
    return nLayoutsVersion;
}

void CLayouts::GetTitle(std::string& strTitle)
{
    strTitle = "Layouts";
}

void CLayouts::GetDescription(std::string& strDescription)
{
    strDescription = "Layouts of window controls";
}

LAYOUTS_API int nLayoutsVersion = 0.2;

LAYOUTS_API int LayoutsVersion(void)
{
    return nLayoutsVersion;
}

/**
 * \~english @mainpage Main Page
 * \~english The project aims to restore visual order among the controls of dialog forms and make them pretty and clear.
 * \~english It provides programmers with simple paradigm for managing controls and flexible tools for building forms based on form layouts and compositions of controls.
 * \~russian @mainpage Титульная страница
 * \~russian Layouts разработан, чтобы навести порядок среди контролов диалоговых форм, делая их аккуратными и ясными. 
 * \~russian Проект обеспечивает программистов простой парадигмой расположения контролов и гибкими инструментами, чтобы собрать форму основанную на размещениях и композициях контролов.
 */
