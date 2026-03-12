
/**
 * \file LayoutSize.h
 * \brief Файл работы c размерами содержимого размещений
 * \details
 * Этот файл содержит реализацию средств работы с размерами содержимого размещений
 * \see LayoutPoint.h
 * \see LayoutRect.h
 */

#ifndef LAYOUTSIZE_HEADER
#define LAYOUTSIZE_HEADER

#include "Layouts.h"

namespace Layouts
{
	class CMargins;

	/*!
	\class CSize
	\brief Размер
	\details
	Размер, который используется для расположения содержимого размещений
	*/
	class LAYOUTS_API CSize
	{
		//@{
		int m_iWidth; ///< Размер по ширине
		int m_iHeight; ///< Размер по высоте
		//@}

	public:

		/**
		* \brief Конструктор класса по-умолчанию
		*/
		CSize();
		
		/** 
		* \brief Конструктор копирования
		* \param[in] Size
		*/
		CSize(const CSize& Size);

		/** 
		* \brief Конструктор размера с указанием ширины и высоты
		* \param[in] iWidth Размер по ширине
		* \param[in] iHeight Размер по высоте
		*/
		CSize(int iWidth, int iHeight);

		/** 
		* \brief Размер по ширине 
		* \return Размер по ширине 
		*/
		int Width() const;
		
		/** 
		* \brief Размер по высоте
		* \return Размер по ширине
		*/ 
		int Height() const;
		
		/** 
		* \brief Установить размер по ширине
		* \param[in] iWidth Размер по ширине
		*/
		void SetWidth(int iWidth);

		/** 
		* \brief Установить размер по высоте
		* \param[in] iHeight Размер по высоте
		*/
		void SetHeight(int iHeight);
		
		/** 
		* \brief Установить размер по другому экземпляру класса
		* \param[in] Size
		*/
		void SetSize(const CSize& Size);

		/** 
		* \brief Установить размер по ширине и высоте
		* \param[in] iWidth Размер по ширине
		* \param[in] iHeight Размер по высоте
		*/
		void SetSize(int iWidth, int iHeight);

		/** 
		* \brief Добавить отступы к размеру
		* \param[in] Marings
		*/
		void AddMargins(const CMargins& Margins);
		
		/** 
		* \brief Вычесть отступы из размера
		* \param[in] Margins
		*/
		void RemoveMargins(const CMargins& Margins);
	};

}

#endif
