
/**
 * \file LayoutGroup.h
 * \~english @brief File for group layout
 * \~english @details
 * This file contains classes and tools for group layout
 * \~russian @brief Файл размещения элементов в группе
 * \~russian @details
 * Этот файл содержит классы и средства размещения контрола в группе
 * \see LayoutItem.h
 */

#ifndef LAYOUTGROUP_HEADER
#define LAYOUTGROUP_HEADER

#include "Layouts.h"
#include "LayoutItem.h"

#include <list>

namespace Layouts
{
	class CSize;
	class CRectangle;
	class CMargins;
	class CLayoutControl;

	/**
	* \class CLayoutGroup
	* \~english @brief Group layout
	* \~english @details
	* Lays items in horizontal or vertical group
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
		* \~russian @return Значение политики
		*/
		LayoutPolicy HorizontalPolicy() override;
		
		/**
		* \~english @brief Get vertical policy
		* \~english @return Vertical policy value
		* \~russian @brief Получить значение политики по вертикали
		* \~russian @return Значение политики
		*/
		LayoutPolicy VerticalPolicy() override;
		
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
		* \~english @brief Set layout orientation
		* \~english @param[in] Orientation value
		* \~russian @brief Установить ориентацию размещения
		* \~russian @param[in] Ориентация
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
