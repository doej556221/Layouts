
/**
 * \file LayoutControl.h
 * \~english @brief File for control layout
 * \~english @details
 * This file contains classes and tools for control layout
 * \~russian @brief Файл размещения контрола
 * \~russian @details
 * Этот файл содержит классы и средства размещения контрола
 * \see LayoutItem.h
 */

#ifndef LAYOUTCONTROL_HEADER
#define LAYOUTCONTROL_HEADER

#include "Layouts.h"
#include "LayoutItem.h"
#include "LayoutMargins.h"
#include "LayoutRect.h"
#include "LayoutItem.h"

namespace Layouts
{
	/**
	* \class CLayoutControl
	* \~english @brief Control layout item
	* \~english @details
	* Lays control inside its layout area
	* \~russian @brief Размещение контрола
	* \~russian @details
	* Размещает контрол в отведенной для него области
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
		* \~english @brief Constructor with size policy values
		* \~english @param[in] eHorizontalPolicy Horizontal size policy value
		* \~english @param[in] eVerticalPolicy Vertical size policy value
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
		* \~english @brief Get horizontal policy value
		* \~english @return Layout policy value
		* \~russian @brief Получить горизонтальную политику размещения
		* \~russian @return Значение политики размещения
		*/
		LayoutPolicy HorizontalPolicy() override;
		
		/**
		* \~english @brief Get vertical policy value
		* \~english @return Layout policy value
		* \~russian @brief Получить вертикальную политику размещения
		* \~russian @return Значение политики размещения
		*/
		LayoutPolicy VerticalPolicy() override;
		
		/**
		* \~english @brief Set layout policy value
		* \~english @param[in] eHorizontalPolicy Horizontal policy value
		* \~english @param[in] eVerticalPolicy Vertical policy value
		* \~russian @brief Установить политику размещения
		* \~russian @param[in] eHorizontalPolicy Значение горизонтальной политика размещения
		* \~russian @param[in] eVerticalPolicy Значение вертикальной политики размещения
		*/
		void SetPolicy(LayoutPolicy eHorizontalPolicy, LayoutPolicy eVerticalPolicy);
		
		/**
		* \~english @brief Calculate item visibility
		* \~english @return Visibility value
		* \~russian @brief Вычислить видимость элемента
		* \~russian @return Значение видимости
		*/
		bool IsVisible() override;

		/**
		* \~english @brief Place layout contents
		* \~english @param[in] Rectangle layout area
		* \~russian @brief Расположить содержимое размещения
		* \~russian @param[in] Прямоугольная область размещения
		*/
		void Lay(const CRectangle& Rectangle) override;
		
		/**
		* \~english @brief Get minimal size of layout area
		* \~english @return Minimal size value
		* \~russian @brief Получить минимальный размер области размещения
		* \~russian @return Размер области
		*/
		CSize GetMinimal() override;
		
		/**
		* \~english @brief Get inner layout
		* \~english @return Layout item
		* \~russian @brief Получить встроенное размещение
		* \~russian @return Элемент размещение
		*/
		CLayoutItem* Layout() const;

		/**
		* \~english @brief Get inner layout
		* \~english @param[in] Layout item
		* \~russian @brief Установить встроенное размещение
		* \~russian @param[in] Элемент размещение
		*/
		void SetLayout(CLayoutItem* pLayoutItem);
		
		/**
		* \~english @brief Get control margins
		* \~english @return Collection of margin values
		* \~russian @brief Получить отсупы для контрола
		* \~russian @return Значения отступов
		*/
		CMargins GetMargins() const;

		/**
		* \~english @brief Set control margins
		* \~english @param[in] iMargin Margins value
		* \~russian @brief Установить отступы для контрола
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
		* \~english @param[in] Margins Collection of margins values
		* \~russian @brief Установить отступы для контрола
		* \~russian @param[in] Margins Значения отступов
		*/
		void SetMargins(const CMargins& Margins);

		/**
		* \~english @brief Set default control margins
		* \~english @param[in] iMargins Margins value
		* \~russian @brief Установить отступы для контрола по-умолчанию
		* \~russian @param[in] iMargins Значение отступов
		*/
		static void SetDefaultMargins(int iMargins);
		
		/**
		* \~english @brief Set default control margins
		* \~english @param[in] iLeft Left margin value
		* \~english @param[in] iTop Top margin value
		* \~english @param[in] iRight Right margin value
		* \~english @param[in] iBottom Bottom margin value
		* \~russian @brief Установить отступы для контрола по-умолчанию
		* \~russian @param[in] iLeft Значение отступа слева
		* \~russian @param[in] iTop Значение отступа сверху
		* \~russian @param[in] iRight Значение отступа справа
		* \~russian @param[in] iBottom Значение отступа снизу
		*/
		static void SetDefaultMargins(int iLeft, int iTop, int iRight, int iBottom);

		/**
		* \~english @brief Set default control margins
		* \~english @param[in] Margins Collection of margins values
		* \~russian @brief Установить отступы для контрола по-умолчанию
		* \~russian @param[in] Margins Значения отступов
		*/
		static void SetDefaultMargins(const CMargins& Margins);

	protected:

		/**
		* \~english @brief Default control margins
		* \~russian @brief Отступы для контрола по-умолчанию
		*/
		static CMargins m_DefaultMargins;
		
		/**
		* \~english @brief Default control margins
		* \~russian @brief Отступы для контрола по-умолчанию
		*/
		CMargins m_Margins;

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
