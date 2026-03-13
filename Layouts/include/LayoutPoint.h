
/**
 * \file LayoutPoint.h
 * \~english @brief File for layout point
 * \~english @details
 * This file contains classes and tools for layout point
 * \~russian @brief Файл средств работы с положением содержимого размещений
 * \~russian @details
 * Этот файл содержит средства работы с положением содержимого размещений
 * \see LayoutSize.h
 * \see LayoutRect.h
 * \see LayoutMargins.h
 */

#ifndef LAYOUTPOINT_HADER
#define LAYOUTPOINT_HADER

#include "Layouts.h"

namespace Layouts
{
	/**
	* \class CPoint
	* \~english @brief Point
	* \~english @details
	* Point used to place layouts contents
	* \~russian @brief Точка
	* \~russian @details
	* Точка, которая используется для расположения содержимого размещений
	*/
	class LAYOUTS_API CPoint
	{
		/**
		* \~english @brief Top of point
		* \~russian @brief Положение точки сверху
		*/
		int m_iTop;

		/**
		* \~english @brief Left of point
		* \~russian @brief Положение точки слева
		*/
		int m_iLeft;

	public:
	
		/**
		* \~english @brief Default constructor
		* \~russian @brief Конструктор по-умолчанию
		*/
		CPoint();

		/**
		* \~english @brief Copy constructor
		* \~english @param[in] Point Another class object
		* \~russian @brief Конструктор копирования
		* \~russian @param[in] Rectangle Другой экземпляр класса
		*/
		CPoint(const CPoint& Point);

		/**
		* \~english @brief Constructor by left and top positions
		* \~english @param[in] iLeft Left of point
		* \~english @param[in] iTop Top of point
		* \~russian @brief Конструктор по положению точки
		* \~russian @param[in] iLeft Положение точки слева
		* \~russian @param[in] iTop Положение точки сверху
		*/
		CPoint(int iLeft, int iTop);

		/**
		* \~english @brief Get left of point
		* \~english @return Left of point position
		* \~russian @brief Получить положение точки слева
		* \~russian @return Положение точки слева
		*/
		int Left() const;

		/**
		* \~english @brief Get top of point
		* \~english @return Top of point position
		* \~russian @brief Получить положение точки сверху
		* \~russian @return Положение точки сверху
		*/
		int Top() const;


		/**
		* \~english @brief Set left of point
		* \~english @param[in] iLeft Left position of point
		* \~russian @brief Установить положение точки слева
		* \~russian @param[in] iLeft Положение точки слева
		*/
		void SetLeft(int iLeft);

		/**
		* \~english @brief Set top of point
		* \~english @param[in] iTop Top position of point
		* \~russian @brief Установить положение точки сверху
		* \~russian @param[in] iTop Положение точки сверху
		*/
		void SetTop(int iTop);

		/**
		* \~english @brief Set point
		* \~english @param[in] Point Another point
		* \~russian @brief Установить положение точки
		* \~russian @param[in] Point Другая точка
		*/
		void SetPoint(const CPoint& Point);
		
		/**
		* \~english @brief Set point
		* \~english @param[in] iLeft Left of point position
		* \~english @param[in] iTop Top of point position
		* \~russian @brief Установить положение точки
		* \~russian @param[in] iLeft Положение точки слева
		* \~russian @param[in] iTop Положение точки сверху
		*/
		void SetPoint(int iLeft, int iTop);
	};

}

#endif