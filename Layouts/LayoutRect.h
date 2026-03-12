
/**
 * \file LayoutRect.h
 * \brief Файл средств работы с рамками содержимого размещений
 * \details
 * Этот файл содержит средства работы с рамками содержимого размещений
 * \see LayoutPoint.h
 * \see LayoutSize.h
 * \see LayoutMargins.h
 */

#ifndef LAYOUTRECTANGLE_HEADER
#define LAYOUTRECTANGLE_HEADER

#include "Layouts.h"
#include "LayoutPoint.h"

namespace Layouts
{
	class CPoint;
	class CSize;
	class CMargins;

	/*!
	\class CRectangle
	\brief Прямоугольник
	\details
	Прямоугольник, который используется для расположения содержимого размещений
	*/
	class LAYOUTS_API CRectangle
	{
		/** 
		* \~english @brief Left of rectangle
		* \~russian @brief Положение рамки слева 
		*/
		int m_iLeft;
		
		/**
		* \~english @brief Top of rectangle
		* \~russian @brief Положение рамки сверху
		*/
		int m_iTop;
		
		/**
		* \~english @brief Right of rectangle
		* \~russian @brief Положение рамки справа
		*/
		int m_iRight;

		/**
		* \~english @brief Bottom of rectangle
		* \~russian @brief Положение рамки снизу
		*/
		int m_iBottom;

	public:

		/**
		* \~english @brief Default constructor
		* \~russian @brief Конструктор по-умолчанию
		*/
		CRectangle();

		/**
		* \~english @brief Copy constructor
		* \~english @param[in] Rectangle Rectangle
		* \~russian @brief Конструктор копирования
		* \~russian @param[in] Rectangle Рамка
		*/
		CRectangle(const CRectangle& Rectangle);

		/**
		* \~english @brief Constructor by boundaries
		* \~english @param[in] iLeft Left of rectangle
		* \~english @param[in] iTop Top of rectangle
		* \~english @param[in] iRight Right of rectangle
		* \~english @param[in] iBottom Bottom of rectangle
		* \~russian @brief Конструктор по границам
		* \~russian @param[in] iLeft Положение рамки слева
		* \~russian @param[in] iTop Положение рамки сверху
		* \~russian @param[in] iRight Положение рамки справа
		* \~russian @param[in] iBottom Положение рамки снизу
		*/
		CRectangle(int iLeft, int iTop, int iRight, int iBottom);
		
		/**
		* \~english @brief Constructor by position and size
		* \~english @param[in] Point Top left position of rectangle
		* \~english @param[in] Size Size of rectangle
		* \~russian @brief Конструктор по положению и размеру
		* \~russian @param[in] Point Положение рамки сверху слева
		* \~russian @param[in] Size Размер рамки
		*/
		CRectangle(const CPoint& Point, const CSize& Size);

		/**
		* \~english @brief Get left of rectangle
		* \~english @return Left of rectangle position
		* \~russian @brief Получить положение прямоугольника слева
		* \~russian @return Положение прямоугольника слева
		*/
		int Left() const;

		/**
		* \~english @brief Get top of rectangle
		* \~english @return Top of rectangle position
		* \~russian @brief Получить положение прямоугольника сверху
		* \~russian @return Положение прямоугольника сверху
		*/
		int Top() const;

		/**
		* \~english @brief Get right of rectangle
		* \~english @return Right of rectangle position
		* \~russian @brief Получить положение прямоугольника справа
		* \~russian @return Положение прямоугольника справа
		*/
		int Right() const;

		/**
		* \~english @brief Get bottom of rectangle
		* \~english @return Bottom of rectangle position
		* \~russian @brief Получить положение прямоугольника снизу
		* \~russian @return Положение прямоугольника снизу
		*/
		int Bottom() const;

		/**
		* \~english @brief Get width of rectangle
		* \~english @return Width of rectangle
		* \~russian @brief Получить ширину прямоугольника
		* \~russian @return Ширина прямоугольника
		*/
		int Width() const;

		/**
		* \~english @brief Get height of rectangle
		* \~english @return Height of rectangle
		* \~russian @brief Получить высоту прямоугольника
		* \~russian @return Высота прямоугольника
		*/
		int Height() const;

		/**
		* \~english @brief Set left of rectangle
		* \~english @param[in] iLeft Left position of rectangle
		* \~russian @brief Установить положение прямоугольника слева
		* \~russian @param[in] iLeft Положение прямоугольника слева
		*/
		void SetLeft(int iLeft);

		/**
		* \~english @brief Set top of rectangle
		* \~english @param[in] iTop Top position of rectangle
		* \~russian @brief Установить положение прямоугольника сверху
		* \~russian @param[in] iTop Положение прямоугольника сверху
		*/
		void SetTop(int iTop);

		/**
		* \~english @brief Set right of rectangle
		* \~english @param[in] iRight Right position of rectangle
		* \~russian @brief Установить положение прямоугольника справа
		* \~russian @param[in] iRight Положение прямоугольника справа
		*/
		void SetRight(int iRight);

		/**
		* \~english @brief Set bottom of rectangle
		* \~english @param[in] iBottom Bottom position of rectangle
		* \~russian @brief Установить положение прямоугольника снизу
		* \~russian @param[in] iBottom Положение прямоугольника снизу
		*/
		void SetBottom(int iBottom);
				
		/**
		* \~english @brief Get rectangle position
		* \~english @return Top left position of rectangle
		* \~russian @brief Получить положение прямоугольника
		* \~russian @return Положение прямоугольника сверху слева
		*/
		CPoint Point() const;

		/**
		* \~english @brief Set rectangle position
		* \~english @param[in] iLeft Left position of rectangle
		* \~english @param[in] iTop Top position of rectangle
		* \~russian @brief Установить положение прямоугольника
		* \~russian @param[in] iLeft Положение прямоугольника слева
		* \~russian @param[in] iTop Положение прямоугольника сверху
		*/
		void SetPoint(int iLeft, int iTop);

		/**
		* \~english @brief Set rectangle position
		* \~english @param[in] Point Top left point of rectangle
		* \~russian @brief Установить положение прямоугольника
		* \~russian @param[in] Point Положение прямоугольника сверху слева
		*/
		void SetPoint(const CPoint& Point);

		/**
		* \~english @brief Get rectangle position
		* \~english @return Size of rectangle
		* \~russian @brief Получить размер прямоугольника
		* \~russian @return Размер прямоугольника
		*/
		CSize Size() const;

		/**
		* \~english @brief Set rectangle size
		* \~english @param[in] iWidth Width of rectangle
		* \~english @param[in] iHeight Height of rectangle
		* \~russian @brief Установить ширину прямоугольника
		* \~russian @param[in] iWidth Ширина прямоугольника
		* \~russian @param[in] iHeight Высота прямоугольника
		*/
		void SetSize(int iWidth, int iHeight);

		/**
		* \~english @brief Set rectangle size
		* \~english @param[in] Size Size of rectangle
		* \~russian @brief Установить размер прямоугольника
		* \~russian @param[in] iSize Размер прямоугольника
		*/
		void SetSize(const CSize& Size);

		/**
		* \~english @brief Set rectangle width
		* \~english @param[in] iWidth Width of rectangle
		* \~russian @brief Установить ширину прямоугольника
		* \~russian @param[in] iWidth Ширина прямоугольника
		*/
		void SetWidth(int iWidth);

		/**
		* \~english @brief Set rectangle height
		* \~english @param[in] iHeight Height of rectangle
		* \~russian @brief Установить высоту прямоугольника
		* \~russian @param[in] iHeight Высота прямоугольника
		*/
		void SetHeight(int iHeight);

		/**
		* \~english @brief Set rectangle
		* \~english @param[in] Rectangle Another rectangle
		* \~russian @brief Установить прямоугольник
		* \~russian @param[in] Rectangle Другой прямоугольник
		*/
		void SetRectangle(const CRectangle& Rectangle);
		
		/**
		* \~english @brief Set rectangle
		* \~english @param[in] Point Top left position of rectangle
		* \~english @param[in] Size Size of rectangle
		* \~russian @brief Установить прямоугольник
		* \~russian @param[in] Point Положение прямоугольника сверху слева
		* \~russian @param[in] Size Размер прямоугольника
		*/
		void SetRectangle(const CPoint& Point, const CSize& Size);

		/**
		* \~english @brief Set rectangle
		* \~english @param[in] iLeft Left position of rectangle
		* \~english @param[in] iRight Right position of rectangle
		* \~english @param[in] iRight Right position of rectangle
		* \~english @param[in] iBottom Bottom position of rectangle
		* \~russian @brief Установить прямоугольник
		* \~russian @param[in] iLeft Положение прямоугольника слева
		* \~russian @param[in] iTop Положение прямоугольника сверху
		* \~russian @param[in] iRight Положение прямоугольника справа
		* \~russian @param[in] iBottom Положение прямоугольника снизу
		*/
		void SetRectangle(int iLeft, int iTop, int iRight, int iBottom);

		/**
		* \~english @brief Add margins to rectangle
		* \~english @param[in] Margins Collection of values to remove from rectangle
		* \~russian @brief Добавить отступы к прямоугольнику
		* \~russian @param[in] Margins Коллекция значений для добавления к прямоугольнику
		*/
		void AddMargins(const CMargins& Margins);

		/**
		* \~english @brief Add margins to rectangle
		* \~english @param[in] iMargins Margin value to remove from rectangle
		* \~russian @brief Добавить отступы к прямоугольнику
		* \~russian @param[in] iMargins Значение отступов для вычитания из прямоугольника
		*/
		void AddMargins(int iMargins);

		/**
		* \~english @brief Remove margins from rectangle
		* \~english @param[in] Margins Collection of values to remove from rectangle
		* \~russian @brief Вычесть отступы из прямоугольника
		* \~russian @param[in] Margins Коллекция значений для отступов из прямоугольника
		*/
		void RemoveMargins(const CMargins& Margins);
	
		/**
		* \~english @brief Remove margins from rectangle
		* \~english @param[in] iMargins Margin value to remove from rectangle
		* \~russian @brief Вычесть отступы из прямоугольника
		* \~russian @param[in] iMargins Значение отступов для вычитания из прямоугольника
		*/
		void RemoveMargins(int iMargins);
	};

}

#endif
