#include "dkpch.h"
#include "Buffer.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Duke
{

    VertexBuffer *VertexBuffer::Create(float *vertices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:
            ASSERT(false);
        case RendererAPI::OpenGL:
            return new OpenGLVertexBuffer(vertices, size);
        }
        ASSERT(false);
        return nullptr;
    }

    IndexBuffer *IndexBuffer::Create(uint32_t *indices, uint32_t count)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:
            ASSERT(false);
        case RendererAPI::OpenGL:
            return new OpenGLIndexBuffer(indices, count);
            ;
        }
        ASSERT(false);
        return nullptr;
    };
}