
/**
 * \file LayoutItem.h
 * \~english @brief File for base layout item
 * \~english @details
 * This file contains classes and tools for base layout item
 * \~russian @brief Файл базового элемента размещений
 * \~russian @details
 * Этот файл содержит классы и средства базового размещения
 */

#ifndef LAYOUTITEM_HEADER
#define LAYOUTITEM_HEADER

#include "Layouts.h"

namespace Layouts
{
	class CLayoutSize;
	class CLayoutRectangle;
	class CLayoutMargins;

	/**
	* \class CLayoutItem
	* \~english @brief Layout item
	* \~english @details
	* Layout item used for derived layouts
	* \~russian @brief Элемент размещения
	* \~russian @details
	* Элемент размещения, который используется производными размещениями
	*/
	class LAYOUTS_API CLayoutItem
	{
	public:
		
		/**
		* \~english @brief Default constructor
		* \~russian @brief Конструктор по-умолчанию
		*/
		CLayoutItem();
		
		/**
		* \~english @brief Destructor
		* \~russian @brief Деструктор
		*/
		virtual ~CLayoutItem();

		/**
		* \~english @brief Get horizontal policy
		* \~english @return Horizontal policy value
		* \~russian @brief Получить значение политики по горизонтали
		* \~russian @return Значение политики
		*/
		virtual LayoutPolicy HorizontalPolicy();

		/**
		* \~english @brief Get vertical policy
		* \~english @return Vertical policy value
		* \~russian @brief Получить значение политики по вертикали
		* \~russian @return Значение политики
		*/
		virtual LayoutPolicy VerticalPolicy();
		
		/**
		* \~english @brief Calculate item visibility
		* \~english @return Visibility value
		* \~russian @brief Вычислить видимость элемента
		* \~russian @return Значение видимости
		*/
		virtual bool IsVisible();

		/**
		* \~english @brief Place layout contents
		* \~english @param[in] Rectangle layout area
		* \~russian @brief Расположить содержимое размещения
		* \~russian @param[in] Прямоугольная область размещения
		*/
		virtual void Lay(const CLayoutRectangle& Rectangle);

		/**
		* \~english @brief Get minimal size of layout area 
		* \~english @return Minimal size value
		* \~russian @brief Получить минимальный размер области размещения
		* \~russian @return Размер области
		*/
		virtual CLayoutSize GetMinimal();

		/**
		* \~english @brief Get spacing
		* \~english @return Spacing value
		* \~russian @brief Получить расстояние между элементами
		* \~russian @return Значение расстояния
		*/
		int Spacing();

		/**
		* \~english @brief Get default spacing
		* \~english @return Spacing value
		* \~russian @brief Получить расстояние между элементами по-умолчанию
		* \~russian @return Значение расстояния
		*/
		static void SetDefaultSpacing(int iSpacing);

		/**
		* \~english @brief Set spacing
		* \~english @param[in] Spacing value
		* \~russian @brief Установить значение расстояния между элементами
		* \~russian @param[in] Значение расстояния
		*/
		void SetSpacing(int iSpacing);

	protected:

		/**
		* \~english @brief Default spacing
		* \~russian @brief Расстояние между элементами по-умолчанию
		*/
		static int m_iDefaultSpacing;

		/**
		* \~english @brief Spacing
		* \~russian @brief Расстояние между элементами
		*/
		int m_iSpacing;
	};

}

#endif
