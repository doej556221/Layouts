
/**
 * \file LayoutMargins.h
 * \~english @brief File for layout margins
 * \~english @details
 * This file contains classes and tools for layout margins
 * \~russian @brief Файл средств работы с отступами содержимого размещений
 * \~russian @details
 * Этот файл содержит средства работы с отступами содержимого размещений
 * \see LayoutPoint.h
 * \see LayoutSize.h
 * \see LayoutRect.h
 */

#ifndef LAYOUTMARGINS_HEADER
#define LAYOUTMARGINS_HEADER

#include "Layouts.h"

namespace Layouts
{
	/**
	* \class CLayoutMargins
	* \~english @brief Margins
	* \~english @details
	* Margins used to place layouts contents
	* \~russian @brief Отступы
	* \~russian @details
	* Отступы, которые используются для расположения содержимого размещений
	*/
	class LAYOUTS_API CLayoutMargins
	{
		/**
		* \~english @brief Left margin
		* \~russian @brief Отступ слева
		*/
		int m_iLeft;

		/**
		* \~english @brief Top margin
		* \~russian @brief Отступ сверху
		*/
		int m_iTop;

		/**
		* \~english @brief Right margin
		* \~russian @brief Отступ справа
		*/
		int m_iRight;

		/**
		* \~english @brief Bottom margin
		* \~russian @brief Отступ снизу
		*/
		int m_iBottom;


	public:

		/**
		* \~english @brief Default constructor
		* \~russian @brief Конструктор по-умолчанию
		*/
		CLayoutMargins();

		/**
		* \~english @brief Copy constructor
		* \~english @param[in] Margins Another class object
		* \~russian @brief Конструктор копирования
		* \~russian @param[in] Margins Другой экземпляр класса
		*/
		CLayoutMargins(const CLayoutMargins& Margins);

		/**
		* \~english @brief Constructor by margin values
		* \~english @param[in] iLeft Left margin
		* \~english @param[in] iTop Top margin
		* \~english @param[in] iRight Right margin
		* \~english @param[in] iBottom Bottom margin
		* \~russian @brief Конструктор значениям оступа
		* \~russian @param[in] iLeft Отступ слева
		* \~russian @param[in] iTop Отступ сверху
		* \~russian @param[in] iRight Отступ справа
		* \~russian @param[in] iBottom Отступ снизу
		*/
		CLayoutMargins(int iTop, int iLeft, int iBottom, int iRight);

		/**
		* \~english @brief Сonstructor by margin value
		* \~english @param[in] iMargin Margin value
		* \~russian @brief Конструктор по значению отступа
		* \~russian @param[in] iMargin Значение отступа
		*/
		CLayoutMargins(int iMargin);

		/**
		* \~english @brief Get left margin value
		* \~english @return Left margin value
		* \~russian @brief Получить значение отступа слева
		* \~russian @return Значение отступа слева
		*/
		int Left() const;

		/**
		* \~english @brief Get top margin value
		* \~english @return Top margin value
		* \~russian @brief Получить значение отступа сверху
		* \~russian @return Значение отступа сверху
		*/
		int Top() const;

		/**
		* \~english @brief Get right margin value
		* \~english @return Right margin value
		* \~russian @brief Получить значение отступа справа
		* \~russian @return Значение отступа справа
		*/
		int Right() const;

		/**
		* \~english @brief Get bottom margin value
		* \~english @return Bottom margin value
		* \~russian @brief Получить значение отступа снизу
		* \~russian @return Значение отступа снизу
		*/
		int Bottom() const;

		/**
		* \~english @brief Set left margin value
		* \~english @param[in] iLeft Left margin value
		* \~russian @brief Установить значение отступа слева
		* \~russian @param[in] iLeft Значение отступа слева
		*/
		void SetLeft(int iLeft);

		/**
		* \~english @brief Set top margin value
		* \~english @param[in] iTop Top margin value
		* \~russian @brief Установить значение отступа сверху
		* \~russian @param[in] iTop Значение отступа сверху
		*/
		void SetTop(int iTop);

		/**
		* \~english @brief Set right margin value
		* \~english @param[in] iRight Right margin value
		* \~russian @brief Установить значение отступа справа
		* \~russian @param[in] iRight Значение отступа справа
		*/
		void SetRight(int iRight);

		/**
		* \~english @brief Set bottom margin value
		* \~english @param[in] iBottom Bottom margin value
		* \~russian @brief Установить значение отступа снизу
		* \~russian @param[in] iBottom Значение отступа снизу
		*/
		void SetBottom(int iBottom);

		/**
		* \~english @brief Set margins
		* \~english @param[in] Margins Collection of margin values
		* \~russian @brief Установить отступы
		* \~russian @param[in] Margins Коллекция значений отступов
		*/
		void SetMargins(const CLayoutMargins& Margins);

		/**
		* \~english @brief Set margins
		* \~english @param[in] iMargin Margins value
		* \~russian @brief Установить отступы
		* \~russian @param[in] iMargin Значение оступов
		*/
		void SetMargins(int iMargin);

		/**
		* \~english @brief Set margins
		* \~english @param[in] iLeft Left margin value
		* \~english @param[in] iRight Right margin value
		* \~english @param[in] iTop Top margin value 
		* \~english @param[in] iBottom Bottom margin value
		* \~russian @brief Установить прямоугольник
		* \~russian @param[in] iLeft Значение отступа слева
		* \~russian @param[in] iTop Значение отступа сверху
		* \~russian @param[in] iRight Значение отступа справа
		* \~russian @param[in] iBottom Значение отступа снизу
		*/
		void SetMargins(int iLeft, int iTop, int iRight, int iBottom);
	};

}

#endif
