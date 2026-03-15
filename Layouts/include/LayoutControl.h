
/**
 * \file LayoutControl.h
 * \~english @brief File for control layout
 * \~english @details
 * This file contains classes and tools for control layout
 * \~russian @brief Файл для размещения контрола
 * \~russian @details
 * Этот файл содержит классы и средства для размещения контрола
 * \see LayoutItem.h
 */

#ifndef LAYOUTCONTROL_HEADER
#define LAYOUTCONTROL_HEADER

#include "Layouts.h"
#include "LayoutItem.h"
#include "LayoutMargins.h"
#include "LayoutRect.h"

namespace Layouts
{
	/**
	* \class CLayoutControl
	* \~english @brief Control layout item
	* \~english @details
	* It places control inside its layout area
	* \~russian @brief Размещение контрола
	* \~russian @details
	* Размещает контрол в своей области
	*/
	class LAYOUTS_API CLayoutControl : public CLayoutItem
	{
	public:

		/**
		* \~english @brief Default constructor
		* \~russian @brief Конструктор по-умолчанию
		*/
		CLayoutControl();

		/**
		* \~english @brief Constructor with layout policies
		* \~english @param[in] eHorizontalPolicy Horizontal layout policy
		* \~english @param[in] eVerticalPolicy Vertical layout policy
		* \~russian @brief Конструктор с указанием политики размещения
		* \~russian @param[in] eHorizontalPolicy Горизонтальная политика размещения
		* \~russian @param[in] eVerticalPolicy Вертикальная политика размещения
		*/
		CLayoutControl(LayoutPolicy eHorizontalPolicy, LayoutPolicy eVerticalPolicy);
		
		/**
		* \~english @brief Destructor
		* \~russian @brief Деструктор
		*/
		virtual ~CLayoutControl();

		/**
		* \~english @brief Get horizontal policy
		* \~english @return Layout policy value
		* \~russian @brief Получить горизонтальную политику размещения
		* \~russian @return Значение политики размещения
		*/
		LayoutPolicy HorizontalPolicy() override;
		
		/**
		* \~english @brief Get vertical policy
		* \~english @return Layout policy value
		* \~russian @brief Получить вертикальную политику размещения
		* \~russian @return Значение политики размещения
		*/
		LayoutPolicy VerticalPolicy() override;
		
		/**
		* \~english @brief Set layout policies
		* \~english @param[in] eHorizontalPolicy Horizontal policy value
		* \~english @param[in] eVerticalPolicy Vertical policy value
		* \~russian @brief Установить политику размещения
		* \~russian @param[in] eHorizontalPolicy Значение горизонтальной политика размещения
		* \~russian @param[in] eVerticalPolicy Значение вертикальной политики размещения
		*/
		void SetPolicy(LayoutPolicy eHorizontalPolicy, LayoutPolicy eVerticalPolicy);
		
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
		bool IsVisible() override;

		/**
		* \~english @brief Place item control
		* \~english @param[in] Rectangular layout area
		* \~russian @brief Расположить контрол размещения
		* \~russian @param[in] Прямоугольная область размещения
		*/
		void Lay(const CLayoutRectangle& Rectangle) override;
		
		/**
		* \~english @brief Get minimal size of layout area
		* \~english @return Minimal size value
		* \~russian @brief Получить минимальный размер области размещения
		* \~russian @return Размер области
		*/
		CLayoutSize GetMinimal() override;
		
		/**
		* \~english @brief Get inner layout
		* \~english @return Layout item
		* \~russian @brief Получить встроенное размещение
		* \~russian @return Элемент размещения
		*/
		CLayoutItem* Layout() const;

		/**
		* \~english @brief Set inner layout
		* \~english @param[in] Layout item
		* \~russian @brief Установить встроенное размещение
		* \~russian @param[in] Элемент размещения
		*/
		void SetLayout(CLayoutItem* pLayoutItem);
		
		/**
		* \~english @brief Get control margins
		* \~english @return Margin values
		* \~russian @brief Получить отсупы контрола
		* \~russian @return Значения отступов
		*/
		CLayoutMargins GetMargins() const;

		/**
		* \~english @brief Set control margins
		* \~english @param[in] iMargin Margins value
		* \~russian @brief Установить отступы контрола
		* \~russian @param[in] iMargin Значение отступов
		*/
		void SetMargins(int iMargin);
		
		/**
		* \~english @brief Set control margins
		* \~english @param[in] iLeft Left margin value
		* \~english @param[in] iTop Top margin value
		* \~english @param[in] iRight Right margin value
		* \~english @param[in] iBottom Bottom margin value
		* \~russian @brief Установить отступы для контрола
		* \~russian @param[in] iLeft Значение отступа слева
		* \~russian @param[in] iTop Значение отступа сверху
		* \~russian @param[in] iRight Значение отступа справа
		* \~russian @param[in] iBottom Значение отступа снизу
		*/
		void SetMargins(int iLeft, int iTop, int iRight, int iBottom);

		/**
		* \~english @brief Set control margins
		* \~english @param[in] Margins Margin values
		* \~russian @brief Установить отступы контрола
		* \~russian @param[in] Margins Значения отступов
		*/
		void SetMargins(const CLayoutMargins& Margins);

		/**
		* \~english @brief Set default control margins
		* \~english @param[in] iMargins Margins value
		* \~russian @brief Установить отступы контрола по-умолчанию
		* \~russian @param[in] iMargins Значение отступов
		*/
		static void SetDefaultMargins(int iMargins);
		
		/**
		* \~english @brief Set default control margins
		* \~english @param[in] iLeft Left margin value
		* \~english @param[in] iTop Top margin value
		* \~english @param[in] iRight Right margin value
		* \~english @param[in] iBottom Bottom margin value
		* \~russian @brief Установить отступы контрола по-умолчанию
		* \~russian @param[in] iLeft Значение отступа слева
		* \~russian @param[in] iTop Значение отступа сверху
		* \~russian @param[in] iRight Значение отступа справа
		* \~russian @param[in] iBottom Значение отступа снизу
		*/
		static void SetDefaultMargins(int iLeft, int iTop, int iRight, int iBottom);

		/**
		* \~english @brief Set default control margins
		* \~english @param[in] Margins Margin values
		* \~russian @brief Установить отступы контрола по-умолчанию
		* \~russian @param[in] Margins Значения отступов
		*/
		static void SetDefaultMargins(const CLayoutMargins& Margins);

	protected:

		/**
		* \~english @brief Default control margins
		* \~russian @brief Отступы контрола по-умолчанию
		*/
		static CLayoutMargins m_DefaultMargins;
		
		/**
		* \~english @brief Default control margins
		* \~russian @brief Отступы контрола по-умолчанию
		*/
		CLayoutMargins m_Margins;

		/**
		* \~english @brief Horizontal policy
		* \~russian @brief Горизонтальная политика размещения
		*/
		LayoutPolicy m_eHorizontalPolicy;

		/**
		* \~english @brief Vertical policy
		* \~russian @brief Вертикальная политика размещения
		*/
		LayoutPolicy m_eVerticalPolicy;

		/**
		* \~english @brief Inner layout
		* \~russian @brief Встроенный элемент размещения
		*/
		CLayoutItem* m_pLayoutItem;
	};

}

#endif
