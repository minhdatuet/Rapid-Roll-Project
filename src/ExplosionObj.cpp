

#include "ExplosionObj.h"

ExplosionObj::ExplosionObj()
{
    height_frame_ = 0;
    width_frame_ = 0;
    frame_ = 0;
}

ExplosionObj::~ExplosionObj()
{
}

bool ExplosionObj::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObj::LoadImg(path, screen);

    if (ret)
    {
        width_frame_ = rect_.w / NUM_FRAME_EXP;
        height_frame_ = rect_.h;
    }

    return ret;
}

void ExplosionObj::set_clip()
{
    if (width_frame_ > 0 && height_frame_ > 0)
    {
        for (int i=0; i< NUM_FRAME_EXP; i++)
        {
            frame_clip_[i].x = i*width_frame_;
            frame_clip_[i].y = 0;
            frame_clip_[i].w = width_frame_;
            frame_clip_[i].h = height_frame_;
        }
    }


}

void ExplosionObj::Show(SDL_Renderer* screen)
{
    SDL_Rect* current_clip = &frame_clip_[frame_];
    SDL_Rect render_quad = {rect_.x, rect_.y, width_frame_, height_frame_};
    if (current_clip != NULL)
    {
        render_quad.w = current_clip->w;
        render_quad.h = current_clip->h;
    }

    SDL_RenderCopy(screen, p_object_, current_clip, &render_quad);
}
