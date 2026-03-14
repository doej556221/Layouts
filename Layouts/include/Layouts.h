
/**
 * \file Layouts.h
 * \~english @brief File for project functions
 * \~english @details
 * This file contains general project functions
 * \~russian @brief Файл функций проекта
 * \~russian @details
 * Этот файл содержит функции проекта
 */

#ifndef LAYOUTS_HEADER
#define LAYOUTS_HEADER

#ifdef _WINDOWS

#ifdef LAYOUTS_EXPORTS
#define LAYOUTS_API __declspec(dllexport)
#else
#define LAYOUTS_API __declspec(dllimport)
#endif

#else

#ifdef LAYOUTS_EXPORTS
#define LAYOUTS_API __attribute__((visibility("default")))
#else
#define LAYOUTS_API
#endif

#endif

#include <string>

class LAYOUTS_API CLayouts {
public:
	CLayouts(void);

	int GetVersion();

	void GetTitle(std::string& strTitle);
	void GetDescription(std::string& strDescription);
};

extern LAYOUTS_API int nLayoutsVersion;
LAYOUTS_API int LayoutsVersion(void);

namespace Layouts
{
	/**
	 * \class LayoutPolicy
	 * \~english Layout orientation
	 * \~english @details
	 * Orientation that is used to place items in layout	
	 * \~russian @brief Ориентация размещения
	 * \~russian @details
	 * Ориентация, с которой размещение упорядочивает свое содержимое
	 */
	enum Orientation
	{
		Horizontal,
		Vertical
	};

	/**
	 * \class LayoutPolicy
	 * \~english @brief Layout policy
	 * \~english @details
	 * Policy that is used to place items in layout
	 * \~russian @brief Политика размещения
	 * \~russian @details
	 * Политика, c которой размещение упорядчивает свое содержимое
	 */
	enum LayoutPolicy
	{
		/**
		* \~english @brief Minimal layout policy
		* \~russian @brief Минимальная политика размещения
		*/
		Minimal,

		/**
		* \~english @brief Fixed layout policy
		* \~russian @brief Фиксированная политика размещения
		*/
		Fixed,

		/**
		* \~english @brief Preferred layout policy
		* \~russian @brief Предпочтительная политика размещения
		*/
		Preferred,

		/**
		* \~english @brief Stretched layout policy
		* \~russian @brief Растянутая политика размещения
		*/
		Stretched
	};
}

#endif
