
/**
 * \file LayoutPoint.h
 * \~english @brief File for layout point
 * \~english @details
 * This file contains classes and tools for layout point
 * \~russian @brief Файл для положения размещений
 * \~russian @details
 * Этот файл содержит классы и средства для положения размещений
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
	* \class CLayoutPoint
	* \~english @brief Point
	* \~english @details
	* Point that is used to place layout items
	* \~russian @brief Точка
	* \~russian @details
	* Точка, которая используется для расположения размещений
	*/
	class LAYOUTS_API CLayoutPoint
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
		CLayoutPoint();

		/**
		* \~english @brief Copy constructor
		* \~english @param[in] Point Another object
		* \~russian @brief Конструктор копирования
		* \~russian @param[in] Rectangle Другой экземпляр класса
		*/
		CLayoutPoint(const CLayoutPoint& Point);

		/**
		* \~english @brief Constructor with left and top positions
		* \~english @param[in] iLeft Left position of point
		* \~english @param[in] iTop Top position of point
		* \~russian @brief Конструктор по положению точки
		* \~russian @param[in] iLeft Положение точки слева
		* \~russian @param[in] iTop Положение точки сверху
		*/
		CLayoutPoint(int iLeft, int iTop);

		/**
		* \~english @brief Get left of point
		* \~english @return Left of point position
		* \~russian @brief Получить положение точки слева
		* \~russian @return Положение точки слева
		*/
		int Left() const;

		/**
		* \~english @brief Get top position of point
		* \~english @return Top position of point
		* \~russian @brief Получить положение точки сверху
		* \~russian @return Положение точки сверху
		*/
		int Top() const;


		/**
		* \~english @brief Set left position of point
		* \~english @param[in] iLeft Left position of point
		* \~russian @brief Установить положение точки слева
		* \~russian @param[in] iLeft Положение точки слева
		*/
		void SetLeft(int iLeft);

		/**
		* \~english @brief Set top position of point
		* \~english @param[in] iTop Top position of point
		* \~russian @brief Установить положение точки сверху
		* \~russian @param[in] iTop Положение точки сверху
		*/
		void SetTop(int iTop);

		/**
		* \~english @brief Set point
		* \~english @param[in] Point Point
		* \~russian @brief Установить положение точки
		* \~russian @param[in] Point Точка
		*/
		void SetPoint(const CLayoutPoint& Point);
		
		/**
		* \~english @brief Set point
		* \~english @param[in] iLeft Left position of point
		* \~english @param[in] iTop Top position of point
		* \~russian @brief Установить положение точки
		* \~russian @param[in] iLeft Положение точки слева
		* \~russian @param[in] iTop Положение точки сверху
		*/
		void SetPoint(int iLeft, int iTop);
	};

}

#endif