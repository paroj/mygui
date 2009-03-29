/*!
	@file
	@author		Albert Semenov
	@date		10/2008
	@module
*//*
	This file is part of MyGUI.
	
	MyGUI is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	
	MyGUI is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License
	along with MyGUI.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "MyGUI_Precompiled.h"
#include "MyGUI_ScrollViewBase.h"
#include "MyGUI_VScroll.h"
#include "MyGUI_HScroll.h"

namespace MyGUI
{

	ScrollViewBase::ScrollViewBase() :
		mHRange(0),
		mVRange(0),
		mShowHScroll(true),
		mShowVScroll(true),
		mHScroll(nullptr),
		mVScroll(nullptr),
		mClient(nullptr),
		mChangeContentByResize(false)
	{
	}

	void ScrollViewBase::updateScrollSize()
	{
		IntSize contentSize = getContentSize();
		IntSize viewSize = getViewSize();

		// ������������ ������� �� ����������
		if (contentSize.height > viewSize.height)
		{
			if (mVScroll != nullptr)
			{
				if (( ! mVScroll->isVisible()) && (mShowVScroll))
				{
					mVScroll->setVisible(true);
					mClient->setSize(mClient->getWidth() - mVScroll->getWidth(), mClient->getHeight());

					// ������ ����� ����������
					if (mChangeContentByResize)
					{
						contentSize = getContentSize();
						viewSize = getViewSize();
					}

					if (mHScroll != nullptr)
					{
						mHScroll->setSize(mHScroll->getWidth() - mVScroll->getWidth(), mHScroll->getHeight());

						// ���� �������� ������������ ����� ���, ����������� ��� �� �����������,
						// ������������� �������������� ����� �� ������� ������
						if ((contentSize.width > viewSize.width) && ( ! mHScroll->isVisible()) && (mShowHScroll))
						{
							mHScroll->setVisible(true);
							mClient->setSize(mClient->getWidth(), mClient->getHeight() - mHScroll->getHeight());
							mVScroll->setSize(mVScroll->getWidth(), mVScroll->getHeight() - mHScroll->getHeight());

							// ������ ����� ����������
							if (mChangeContentByResize)
							{
								contentSize = getContentSize();
								viewSize = getViewSize();
							}

						}
					}
				}
			}
		}
		// ������������ ������� ����������
		else
		{
			if (mVScroll != nullptr)
			{
				if (mVScroll->isVisible())
				{
					mVScroll->setVisible(false);
					mClient->setSize(mClient->getWidth() + mVScroll->getWidth(), mClient->getHeight());

					// ������ ����� ����������
					if (mChangeContentByResize)
					{
						contentSize = getContentSize();
						viewSize = getViewSize();
					}

					if (mHScroll != nullptr)
					{
						mHScroll->setSize(mHScroll->getWidth() + mVScroll->getWidth(), mHScroll->getHeight());

						// ���� ������ ������������ ����� ���, ����������� ��� �� �����������,
						// ������������� �������������� ����� �� ������� �������
						if ((contentSize.width <= viewSize.width) && (mHScroll->isVisible()))
						{
							mHScroll->setVisible(false);
							mClient->setSize(mClient->getWidth(), mClient->getHeight() + mHScroll->getHeight());
							mVScroll->setSize(mVScroll->getWidth(), mVScroll->getHeight() + mHScroll->getHeight());

							// ������ ����� ����������
							if (mChangeContentByResize)
							{
								contentSize = getContentSize();
								viewSize = getViewSize();
							}

						}
					}
				}
			}
		}


		// �������������� ������� �� ����������
		if (contentSize.width > viewSize.width)
		{
			if (mHScroll != nullptr)
			{
				if (( ! mHScroll->isVisible()) && (mShowHScroll))
				{
					mHScroll->setVisible(true);
					mClient->setSize(mClient->getWidth(), mClient->getHeight() - mHScroll->getHeight());

					// ������ ����� ����������
					if (mChangeContentByResize)
					{
						contentSize = getContentSize();
						viewSize = getViewSize();
					}

					if (mVScroll != nullptr)
					{
						mVScroll->setSize(mVScroll->getWidth(), mVScroll->getHeight() - mHScroll->getHeight());

						// ���� �������� �������������� ����� ���, ����������� ��� �� ���������,
						// ������������� ������������ ����� �� ������� ������
						if ((contentSize.height > viewSize.height) && ( ! mVScroll->isVisible()) && (mShowVScroll))
						{
							mVScroll->setVisible(true);
							mClient->setSize(mClient->getWidth() - mVScroll->getWidth(), mClient->getHeight());
							mHScroll->setSize(mHScroll->getWidth() - mVScroll->getWidth(), mHScroll->getHeight());

							// ������ ����� ����������
							if (mChangeContentByResize)
							{
								contentSize = getContentSize();
								viewSize = getViewSize();
							}

						}
					}
				}
			}
		}
		// �������������� ������� ����������
		else
		{
			if (mHScroll != nullptr)
			{
				if (mHScroll->isVisible())
				{
					mHScroll->setVisible(false);
					mClient->setSize(mClient->getWidth(), mClient->getHeight() + mHScroll->getHeight());

					// ������ ����� ����������
					if (mChangeContentByResize)
					{
						contentSize = getContentSize();
						viewSize = getViewSize();
					}

					if (mVScroll != nullptr)
					{
						mVScroll->setSize(mVScroll->getWidth(), mVScroll->getHeight() + mHScroll->getHeight());

						// ���� ������ �������������� ����� ���, ����������� ��� �� ���������,
						// ������������� ������������ ����� �� ������� �������
						if ((contentSize.height <= viewSize.height) && (mVScroll->isVisible()))
						{
							mVScroll->setVisible(false);
							mClient->setSize(mClient->getWidth() + mVScroll->getWidth(), mClient->getHeight());
							mHScroll->setSize(mHScroll->getWidth() + mVScroll->getWidth(), mHScroll->getHeight());

							// ������ ����� ����������
							if (mChangeContentByResize)
							{
								contentSize = getContentSize();
								viewSize = getViewSize();
							}
						}
					}
				}
			}
		}

		mVRange = (viewSize.height >= contentSize.height) ? 0 : contentSize.height - viewSize.height;
		mHRange = (viewSize.width >= contentSize.width) ? 0 : contentSize.width - viewSize.width;

		size_t page = getScrollPage();
		if (mVScroll != nullptr)
		{
			mVScroll->setScrollPage(page);
			mVScroll->setScrollViewPage(viewSize.width > (int)page ? viewSize.width : page);
			mVScroll->setScrollRange(mVRange + 1);
			if (contentSize.height) mVScroll->setTrackSize(int (float(mVScroll->getLineSize() * viewSize.height) / float(contentSize.height)));
		}
		if (mHScroll != nullptr)
		{
			mHScroll->setScrollPage(page);
			mHScroll->setScrollViewPage(viewSize.height > (int)page ? viewSize.height : page);
			mHScroll->setScrollRange(mHRange + 1);
			if (contentSize.width) mHScroll->setTrackSize(int (float(mHScroll->getLineSize() * viewSize.width) / float(contentSize.width)));
		}
	}

	void ScrollViewBase::updateScrollPosition()
	{
		// ������ ���������
		IntSize contentSize = getContentSize();
		// ������� �������� ���������
		IntPoint contentPoint = getContentPosition();
		// ��������� ��������
		IntPoint offset = contentPoint;

		IntSize viewSize = getViewSize();

		Align align = getContentAlign();

		if (contentSize.width > viewSize.width)
		{
			// ������������ ����� �����
			if ((offset.left + viewSize.width) > contentSize.width)
			{
				offset.left = contentSize.width - viewSize.width;
			}
			// ������������ ����� ������
			else if (offset.left < 0)
			{
				offset.left = 0;
			}
		}
		else
		{
			if (align.isLeft())
			{
				offset.left = 0;
			}
			else if (align.isRight())
			{
				offset.left = contentSize.width - viewSize.width;
			}
			else
			{
				offset.left = (contentSize.width - viewSize.width) / 2;
			}
		}

		if (contentSize.height > viewSize.height)
		{
			// ������������ ����� �����
			if ((offset.top + viewSize.height) > contentSize.height)
			{
				offset.top = contentSize.height - viewSize.height;
			}
			// ������������ ����� ����
			else if (offset.top < 0)
			{
				offset.top = 0;
			}
		}
		else
		{
			if (align.isTop())
			{
				offset.top = 0;
			}
			else if (align.isBottom())
			{
				offset.top = contentSize.height - viewSize.height;
			}
			else
			{
				offset.top = (contentSize.height - viewSize.height) / 2;
			}
		}

		if (offset != contentPoint)
		{
			if (nullptr != mVScroll) mVScroll->setScrollPosition(offset.top);
			if (nullptr != mHScroll) mHScroll->setScrollPosition(offset.left);
			setContentPosition(offset);
		}
	}

} // namespace MyGUI
