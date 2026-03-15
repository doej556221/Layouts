
/**
 * \file LayoutGroup.h
 * \~english @brief File for group layout
 * \~english @details
 * This file contains classes and tools for group layout
 * \~russian @brief Файл для размещения элементов в группе
 * \~russian @details
 * Этот файл содержит классы и средства для размещения элементов в группе
 * \see LayoutItem.h
 */

#ifndef LAYOUTGROUP_HEADER
#define LAYOUTGROUP_HEADER

#include "Layouts.h"
#include "LayoutItem.h"
#include "LayoutMargins.h"
#include "LayoutRect.h"
#include "LayoutSize.h"

#include <list>

namespace Layouts
{
	/**
	* \class CLayoutGroup
	* \~english @brief Group layout
	* \~english @details
	* It places items in horizontal or vertical group
	* \~russian @brief Размещение в группе
	* \~russian @details
	* Размещает элементы в горизонтальной или вертикальной группе
	*/
	class LAYOUTS_API CLayoutGroup : public CLayoutItem
	{
	public:

		/**
		* \~english @brief Default constructor
		* \~russian @brief Конструктор по-умолчанию
		*/
		CLayoutGroup();

		/**
		* \~english @brief Constructor with layout orientation
		* \~english @param[in] eOrientation Orientation value
		* \~russian @brief Конструктор с указанием ориентации размещения
		* \~russian @param[in] eOrientation Ориентация размещения
		*/
		CLayoutGroup(Orientation eOrientation);

		/**
		* \~english @brief Destructor
		* \~russian @brief Деструктор
		*/
		virtual ~CLayoutGroup();

		/**
		* \~english @brief Add item
		* \~english @param[in] Layout item
		* \~russian @brief Добавить элемент размещения
		* \~russian @param[in] Элемент размещения
		*/
		void AddItem(CLayoutItem* pItem);

		/**
		* \~english @brief Remove item
		* \~english @param[in] Layout item
		* \~russian @brief Удалить элемент размещения
		* \~russian @param[in] Элемент размещения
		*/
		void RemoveItem(CLayoutItem* pItem);

		/**
		* \~english @brief Count items
		* \~english @return Number of items
		* \~russian @brief Получить количество элементов
		* \~russian @return Количество элементов
		*/
		int CountItems();

		/**
		* \~english @brief Get horizontal policy
		* \~english @return Horizontal policy value
		* \~russian @brief Получить значение политики по горизонтали
		* \~russian @return Значение политики размещения
		*/
		LayoutPolicy HorizontalPolicy() override;
		
		/**
		* \~english @brief Get vertical policy
		* \~english @return Vertical policy value
		* \~russian @brief Получить значение политики по вертикали
		* \~russian @return Значение политики размещения
		*/
		LayoutPolicy VerticalPolicy() override;
		
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
		* \~english @brief Place layout items
		* \~english @param[in] Rectangular layout area
		* \~russian @brief Расположить элементы размещения
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
		* \~english @brief Set layout orientation
		* \~english @param[in] Orientation value
		* \~russian @brief Установить ориентацию размещения
		* \~russian @param[in] Значение ориентации
		*/
		void SetOrientation(Orientation Value);

	protected:

		/**
		* \~english @brief Layout orientation
		* \~russian @brief Ориентация размещения
		*/
		Orientation m_eOrientation;

		/**
		* \~english @brief Layout items
		* \~russian @brief Элементы размещения
		*/
		std::list<CLayoutItem*> m_arrItems;
	};

}

#endif
