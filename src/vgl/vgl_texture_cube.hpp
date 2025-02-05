#ifndef VGL_TEXTURE_CUBE_HPP
#define VGL_TEXTURE_CUBE_HPP

/// Cube map  texture.
class TextureCube : public Texture
{
private:
#if defined(VGL_USE_LD)
    /// Side size in pixels.
    unsigned int m_side = 0;
#endif

public:
    /// Constructor.
    explicit TextureCube() :
        Texture(GL_TEXTURE_CUBE_MAP)
    {
    }

private:
    /// Update single side of the cube map.
    /// \param tex Texture to update.
    /// \param img Image to update with.
    /// \param bpc Bytes per component to convert the image to (default: 1).
    void updateSide(GLenum target, Image2D& img, unsigned bpc)
    {
        TextureFormat format(img.getChannelCount(), bpc, reinterpret_cast<void*>(1u));

        unsigned width = img.getWidth();
#if defined(VGL_USE_LD)
        {
            unsigned height = img.getHeight();
            if(width != height)
            {
                VGL_THROW_RUNTIME_ERROR("cube map width (" + to_string(width) + ") and height (" + to_string(height) +
                        ") do not match");
            }
        }

        if(m_side && (m_side != width))
        {
            VGL_THROW_RUNTIME_ERROR("new image has mismatching cube map side length: " + to_string(width) + " vs. " +
                   to_string(m_side));
        }
        m_side = width;
#endif

        uarr<uint8_t> export_data = img.getExportData(bpc);

        dnload_glTexImage2D(target, 0, format.getInternalFormat(),
                static_cast<GLsizei>(width), static_cast<GLsizei>(width),
                0, format.getFormat(), format.getType(), export_data.get());
    }

public:
    /// Update texture contents with an image.
    ///
    /// \param img Image to update with.
    /// \param bpc Bytes per component to convert the image to (default: 1).
    /// \param filtering Filtering mode (default: trilinear).
    /// \param clamp True to clamp texture instead of wrapping (default: false).
    template<typename T> void update(T& img, unsigned bpc = 1, FilteringMode filtering = TRILINEAR)
    {
        dnload_glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

        const Texture* prev_texture = updateBegin();

        updateSide(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, img.getSideNegX(), bpc);
        updateSide(GL_TEXTURE_CUBE_MAP_POSITIVE_X, img.getSidePosX(), bpc);
        updateSide(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, img.getSideNegY(), bpc);
        updateSide(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, img.getSidePosY(), bpc);
        updateSide(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, img.getSideNegZ(), bpc);
        updateSide(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, img.getSidePosZ(), bpc);

        // Seamless cube map enabled -> wrap mode does not need to be set.
        setFiltering(reinterpret_cast<void*>(1), filtering);

        updateEnd(prev_texture);
    }
};

#endif
