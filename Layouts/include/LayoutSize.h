
/**
 * \file LayoutSize.h
 * \~english @brief File for layout size
 * \~english @details
 * This file contains classes and tools for layout size
 * \~russian @brief Файл для размера размещений
 * \~russian @details
 * Этот файл содержит классы и средства для размера размещений
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
	* Size that is used to place layouts contents
	* \~russian @brief Размер
	* \~russian @details
	* Размер, который используется для расположения размещений
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
		* \~english @param[in] Size Another object
		* \~russian @brief Конструктор копирования
		* \~russian @param[in] Size Другой экземляр класса
		*/
		CLayoutSize(const CLayoutSize& Size);

		/** 
		* \~english @brief Constructor with width and height
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
		* \~russian @return Ширина
		*/
		int Width() const;
		
		/** 
		* \~english @brief Get height
		* \~english @return Height
		* \~russian @brief Размер по высоте
		* \~russian @return Высота
		*/ 
		int Height() const;
		
		/** 
		* \~english @brief Set width
		* \~english @param[in] iWidth Width
		* \~russian @brief Установить размер по ширине
		* \~russian @param[in] iWidth Ширина
		*/
		void SetWidth(int iWidth);

		/** 
		* \~english @brief Set height
		* \~english @param[in] iHeight Height
		* \~russian @brief Установить размер по высоте
		* \~russian @param[in] iHeight Высота
		*/
		void SetHeight(int iHeight);
		
		/** 
		* \~english @brief Set size
		* \~english @param[in] Size Size
		* \~russian @brief Установить размер
		* \~russian @param[in] Size Размер
		*/
		void SetSize(const CLayoutSize& Size);

		/** 
		* \~english @brief Set size
		* \~english @param[in] iWidth Width
		* \~english @param[in] iHeight Height
		* \~russian @brief Установить размер по ширине и высоте
		* \~russian @param[in] iWidth Ширина
		* \~russian @param[in] iHeight Высота
		*/
		void SetSize(int iWidth, int iHeight);

		/** 
		* \~english @brief Add margins
		* \~english @param[in] Margins Margins value
		* \~russian @brief Добавить отступы к размеру
		* \~russian @param[in] Marings Значение отступов
		*/
		void AddMargins(const CLayoutMargins& Margins);

		/**
		* \~english @brief Add margins
		* \~english @param[in] iMargins Margins value
		* \~russian @brief Добавить отступы к размеру
		* \~russian @param[in] iMarings Значение отступов
		*/
		void AddMargins(int iMargins);


		/** 
		* \~english @brief Remove margins
		* \~english @param[in] Margins Margins value
		* \~russian @brief Вычесть отступы из размера
		* \~russian @param[in] Margins Значение отступов
		*/
		void RemoveMargins(const CLayoutMargins& Margins);

		/**
		* \~english @brief Remove margins
		* \~english @param[in] iMargins Margins value
		* \~russian @brief Вычесть отступы из размера
		* \~russian @param[in] iMarings Значение отступов
		*/
		void RemoveMargins(int iMargins);

	};

}

#endif
