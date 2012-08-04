/*!
	@file
	@author		Albert Semenov
	@date		08/2012
*/

#ifndef __MYGUI_EXPORT_RENDER_MANAGER_H__
#define __MYGUI_EXPORT_RENDER_MANAGER_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_RenderFormat.h"
#include "MyGUI_RenderManager.h"

namespace MyGUI
{

	class ExportRenderManager :
		public RenderManager,
		public IRenderTarget
	{
	public:
		ExportRenderManager();

		void initialise();
		void shutdown();

		static ExportRenderManager& getInstance()
		{
			return *getInstancePtr();
		}
		static ExportRenderManager* getInstancePtr()
		{
			return static_cast<ExportRenderManager*>(RenderManager::getInstancePtr());
		}

		/** @see RenderManager::getViewSize */
		virtual const IntSize& getViewSize() const
		{
			return mViewSize;
		}

		/** @see RenderManager::getVertexFormat */
		virtual VertexColourType getVertexFormat()
		{
			return VertexColourType::ColourARGB;
		}

		/** @see RenderManager::createVertexBuffer */
		virtual IVertexBuffer* createVertexBuffer();
		/** @see RenderManager::destroyVertexBuffer */
		virtual void destroyVertexBuffer(IVertexBuffer* _buffer);

		/** @see RenderManager::createTexture */
		virtual ITexture* createTexture(const std::string& _name);
		/** @see RenderManager::destroyTexture */
		virtual void destroyTexture(ITexture* _texture);
		/** @see RenderManager::getTexture */
		virtual ITexture* getTexture(const std::string& _name);

		/** @see RenderManager::isFormatSupported */
		virtual bool isFormatSupported(PixelFormat _format, TextureUsage _usage);

		/** @see IRenderTarget::begin */
		virtual void begin();
		/** @see IRenderTarget::end */
		virtual void end();

		/** @see IRenderTarget::doRender */
		virtual void doRender(IVertexBuffer* _buffer, ITexture* _texture, size_t _count);

		/** @see IRenderTarget::getInfo */
		virtual const RenderTargetInfo& getInfo()
		{
			return mInfo;
		}

		/*internal:*/
		void drawOneFrame();
		void setViewSize(int _width, int _height);

	private:
		IntSize mViewSize;
		RenderTargetInfo mInfo;
	};

} // namespace MyGUI

#endif // __MYGUI_EXPORT_RENDER_MANAGER_H__
