#include "Include.hpp"

#ifndef IMGUI_DEFINE_MATH_OPERATORS
static ImVec2 operator+(const ImVec2& a, const ImVec2& b) {
    return ImVec2(a.x + b.x, a.y + b.y);
}

static ImVec2 operator-(const ImVec2& a, const ImVec2& b) {
    return ImVec2(a.x - b.x, a.y - b.y);
}

static ImVec2 operator*(const ImVec2& a, const ImVec2& b) {
    return ImVec2(a.x * b.x, a.y * b.y);
}

static ImVec2 operator/(const ImVec2& a, const ImVec2& b) {
    return ImVec2(a.x / b.x, a.y / b.y);
}

static ImVec2 operator*(const ImVec2& a, const float b) {
    return ImVec2(a.x * b, a.y * b);
}
#endif

Color& Plane::get(int col, int height)
{
    return led[(col * 7) + (col % 2 ? height : 6-height)];
}

Color& CustomData::get(int row, int col, int height)
{
    return planes[row].get(col, height);
}

void CustomGui::Main()
{
    ImGui::SetNextWindowFocus();
    ImGui::SetNextWindowSize(ImVec2(600, 600));
    ImGui::Begin("Example GUI");

    ImGui::Text(("Layer: " + std::to_string(CurLayer)).c_str());
    ImGui::SliderInt("###Layer", &CurLayer, 0, 7);

    ImGui::ColorPicker4("COLOR", CurColor, ImGuiColorEditFlags_AlphaBar);
    ImGui::Text(std::to_string(CurColor[0]).c_str());
    data.get(CurPlace[0], CurPlace[1], CurLayer) = CurColor;
    ImGui::End();
}

void CustomGui::DrawLayer()
{
    ImGui::SetNextWindowSize(ImVec2(900, 900));
    ImGui::SetNextWindowPos(ImVec2(-20, -20));


    ImGui::Begin("Example Grid");

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImGuiIO& io = ImGui::GetIO();
    // Draw the data... 

    int scale = 45;

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            ImColor clr = data.get(r, c, CurLayer).GetImColor();

            ImVec2 Center(scale + (scale * r), scale + (scale * c));
            int ret = 0;
            const ImRect anchor(Center - ImVec2(2, 2), Center + ImVec2(2, 2));
            if (anchor.Contains(io.MousePos))
            {
                ret = 1;
                if (io.MouseDown[0])
                {
                    CurPlace[0] = r;
                    CurPlace[1] = c;
                    CurPlace[2] = CurLayer;
                    
                    data.get(r, c, CurLayer).GetFltColr(CurColor);
                }
            }
            if (ret)
                draw_list->AddCircle(Center, 3, 0xFFFFFFFF);
            else
                draw_list->AddCircle(Center, 3, clr);
        }

        // ORANGE COLOR
        ImVec2 Center(scale + (scale * CurPlace[0]), scale + (scale * CurPlace[1]));
        draw_list->AddCircle(Center, 4, 0xFF4500FF);
    }
    ImGui::End();
}
