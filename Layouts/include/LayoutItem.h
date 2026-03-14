
/**
 * \file LayoutItem.h
 * \~english @brief File for basic layout item
 * \~english @details
 * This file contains classes and tools for basic layout item
 * \~russian @brief Файл для базового элемента размещений
 * \~russian @details
 * Этот файл содержит классы и средства для базового элемента размещений
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
	* \~english @brief Base layout item
	* \~english @details
	* Basic layout item used for derived layouts
	* \~russian @brief Базовый элемент размещений
	* \~russian @details
	* Базовый элемент размещений, который используется производными размещениями
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
		* \~russian @return Значение политики размещения
		*/
		virtual LayoutPolicy HorizontalPolicy();

		/**
		* \~english @brief Get vertical policy
		* \~english @return Vertical policy value
		* \~russian @brief Получить значение политики по вертикали
		* \~russian @return Значение политики размещения
		*/
		virtual LayoutPolicy VerticalPolicy();
		
		/**
		* \~english @brief Get layout visibility
		* \~english @return Visibility value
		* \~details
		* This method returns layout general visibility taking in account its child items
		* \~russian @brief Получить видимость элемента
		* \~russian @return Значение видимости
		* ~russian @details
		* Возвращает общую видимость размещения с учетом его вложенных элементов
		*/
		virtual bool IsVisible();

		/**
		* \~english @brief Place layout items
		* \~english @param[in] Rectangular layout area
		* \~russian @brief Расположить элементы размещения
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
		* \~english @brief Get layout spacing
		* \~english @return Spacing value
		* \~russian @brief Получить расстояние между элементами размещения
		* \~russian @return Значение расстояния
		*/
		int Spacing();

		/**
		* \~english @brief Get layout default spacing
		* \~english @return Spacing value
		* \~russian @brief Получить расстояние между элементами размещения по-умолчанию
		* \~russian @return Значение расстояния
		*/
		static void SetDefaultSpacing(int iSpacing);

		/**
		* \~english @brief Set layout spacing
		* \~english @param[in] Spacing value
		* \~russian @brief Установить значение расстояния между элементами размещения
		* \~russian @param[in] Значение расстояния
		*/
		void SetSpacing(int iSpacing);

	protected:

		/**
		* \~english @brief Default layout spacing
		* \~russian @brief Расстояние между элементами размещения по-умолчанию
		*/
		static int m_iDefaultSpacing;

		/**
		* \~english @brief Layout spacing
		* \~russian @brief Расстояние между элементами размещения
		*/
		int m_iSpacing;
	};

}

#endif
