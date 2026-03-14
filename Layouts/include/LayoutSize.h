
/**
 * \file LayoutSize.h
 * \~english @brief File for layout size
 * \~english @details
 * This file contains classes and tools for layout size
 * \~russian @brief Файл работы c размерами содержимого размещений
 * \~russian @details
 * Этот файл содержит средства работы с размерами содержимого размещений
 * \see LayoutPoint.h
 * \see LayoutRect.h
 */

#ifndef LAYOUTSIZE_HEADER
#define LAYOUTSIZE_HEADER

#include "Layouts.h"

namespace Layouts
{
	class CLayoutMargins;

	/**
	* \class CLayoutSize
	* \~english @brief Size
	* \~english @details
	* Size used to place layouts contents
	* \~russian @brief Размер
	* \~russian @details
	* Размер, который используется для расположения содержимого размещений
	*/
	class LAYOUTS_API CLayoutSize
	{
		/**
		* \~english @brief Width
		* \~russian @brief Размер по ширине
		*/
		int m_iWidth;

		/**
		* \~english @brief Height
		* \~russian @brief Размер по высоте
		*/
		int m_iHeight;

	public:

		/**
		* \~english @brief Default constructor
		* \~russian @brief Конструктор класса по-умолчанию
		*/
		CLayoutSize();
		
		/** 
		* \~english @brief Copy constructor
		* \~english @param[in] Size Another class object
		* \~russian @brief Конструктор копирования
		* \~russian @param[in] Size Другой экземляр класса
		*/
		CLayoutSize(const CLayoutSize& Size);

		/** 
		* \~english @brief Constructor by width and height
		* \~englush @param[in] iWidth Width
		* \~english @param[in] iHeight Height
		* \~russian @brief Конструктор размера по ширине и высоте
		* \~russian @param[in] iWidth Размер по ширине
		* \~russian @param[in] iHeight Размер по высоте
		*/
		CLayoutSize(int iWidth, int iHeight);

		/** 
		* \~english @brief Get width
		* \~english @return Width
		* \~russian @brief Размер по ширине 
		* \~russian @return Размер по ширине 
		*/
		int Width() const;
		
		/** 
		* \~english @brief Get height
		* \~english @return Height
		* \~russian @brief Размер по высоте
		* \~russian @return Размер по ширине
		*/ 
		int Height() const;
		
		/** 
		* \~english @brief Set width
		* \~english @param[in] iWidth Width
		* \~russian @brief Установить размер по ширине
		* \~russian @param[in] iWidth Размер по ширине
		*/
		void SetWidth(int iWidth);

		/** 
		* \~english @brief Set height
		* \~english @param[in] iHeight Height
		* \~russian @brief Установить размер по высоте
		* \~russian @param[in] iHeight Размер по высоте
		*/
		void SetHeight(int iHeight);
		
		/** 
		* \~english @brief Set size
		* \~english @param[in] Size Another size object
		* \~russian @brief Установить размер по другому размеру
		* \~russian @param[in] Size
		*/
		void SetSize(const CLayoutSize& Size);

		/** 
		* \~english @brief Set size
		* \~english @param[in] iWidth Width
		* \~english @param[in] iHeight Height
		* \~russian @brief Установить размер по ширине и высоте
		* \~russian @param[in] iWidth Размер по ширине
		* \~russian @param[in] iHeight Размер по высоте
		*/
		void SetSize(int iWidth, int iHeight);

		/** 
		* \~english @brief Add margins
		* \~english @param[in] Margins Collection of values to add to rectangle
		* \~russian @brief Добавить отступы к размеру
		* \~russian @param[in] Marings
		*/
		void AddMargins(const CLayoutMargins& Margins);

		/**
		* \~english @brief Add margins
		* \~english @param[in] iMargins Margin value to add to rectangle
		* \~russian @brief Добавить отступы к размеру
		* \~russian @param[in] iMarings Значение отступа, которое необходимо добавить к размеру
		*/
		void AddMargins(int iMargins);


		/** 
		* \~english @brief Remove margins
		* \~english @param[in] Margins Collection of values to remove from rectangle
		* \~russian @brief Вычесть отступы из размера
		* \~russian @param[in] Margins
		*/
		void RemoveMargins(const CLayoutMargins& Margins);

		/**
		* \~english @brief Remove margins
		* \~english @param[in] iMargins Margin value to remove from rectangle
		* \~russian @brief Вычесть отступы из размера
		* \~russian @param[in] iMarings Значение отступа, которое необходимо вычесть из размеру
		*/
		void RemoveMargins(int iMargins);

	};

}

#endif
