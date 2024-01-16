#// https://en.wikipedia.org/wiki/Flag_of_South_Korea
// https://en.wikipedia.org/wiki/Flag_of_South_Korea#/media/File:Flag_of_South_Korea_(construction_sheet).svg
#include <stdio.h>
#include <gd.h>
#include <math.h>

// 函式原型
void draw_korean_flag(gdImagePtr img);

// 宣告旋轉函式
void rotatePoints(int x_orig, int y_orig, double rotation_ang, gdPoint *points, int num_points) {
    int i;
    double angle_rad = rotation_ang * M_PI / 180.0;

    for (i = 0; i < num_points; i++) {
        int x = points[i].x - x_orig;
        int y = points[i].y - y_orig;

        points[i].x = x_orig + (int)(x * cos(angle_rad) - y * sin(angle_rad));
        points[i].y = y_orig + (int)(x * sin(angle_rad) + y * cos(angle_rad));
    }
}

int main() {
    // 寬度 3: 高度 2
    int width = 1200;

    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_korean_flag(img);

    FILE *outputFile = fopen("./../images/korea_flag_2.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "錯誤：無法打開輸出檔案。\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_korean_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, blue, black, grey, white;
    // 根據 https://en.wikipedia.org/wiki/Flag_of_South_Korea#/media/File:Flag_of_South_Korea_(construction_sheet).svg
    double scale = width / 72;
    int big_circle_dia = (int)24 * scale;
    int small_circle_dia = (int)big_circle_dia / 2;
    // 左小圓的旋轉角度為 rot_ang
    double rot_ang = atan2(48.0, 72.0);
    // 長方形的旋轉角度為 rot_ang2;
    double rot_ang2 = atan2(72.0, 48.0);
    double degree = M_PI / 180.0;
    int center_x = (int)(width / 2);
    int center_y = (int)(height / 2);
    gdPoint points[4];
    // 上方長方形
    int rect_lower_left_x = center_x - (int)6 * scale;
    int rect_lower_right_x = center_x + (int)6 * scale;
    int rect_upper_left_x = rect_lower_left_x;
    int rect_upper_right_x = rect_lower_right_x;
    int rect_lower_left_y = center_y - (int)18 * scale;
    int rect_lower_right_y = rect_lower_left_y;
    int rect_upper_left_y = rect_lower_left_y - (int)8 * scale;
    int rect_upper_right_y = rect_upper_left_y;
    // 取得點的座標
    points[0].x = rect_lower_left_x;
    points[0].y = rect_lower_left_y;
    points[1].x = rect_upper_left_x;
    points[1].y = rect_upper_left_y;
    points[2].x = rect_upper_right_x;
    points[2].y = rect_upper_right_y;
    points[3].x = rect_lower_right_x;
    points[3].y = rect_lower_right_y;

    printf("small_circle_dia is %d\n", small_circle_dia);
    int left_center_x = center_x - (small_circle_dia / 2) * cos(rot_ang);
    printf("center_x is %d\n", center_x);
    printf("atan2(48.0, 72.0) is %f\n", atan2(48.0, 72.0));
    printf("left_center_x is %d\n", left_center_x);
    int left_center_y = center_y - (small_circle_dia / 2) * sin(rot_ang);
    int right_center_x = center_x + (small_circle_dia / 2) * cos(rot_ang);
    int right_center_y = center_y + (small_circle_dia / 2) * sin(rot_ang);

    red = gdImageColorAllocate(img, 255, 0, 0);      // 紅色
    blue = gdImageColorAllocate(img, 0, 0, 255);     // 藍色
    black = gdImageColorAllocate(img, 0, 0, 0);      // 黑色
    grey = gdImageColorAllocate(img, 125, 125, 125); // 灰色
    white = gdImageColorAllocate(img, 255, 255, 255); // 白色

    gdImageFilledRectangle(img, 0, 0, width, height, white);
    gdImageRectangle(img, 0, 0, width, height, black);

    // 長方形旋轉到右上方
    rotatePoints(center_x, center_y, rot_ang2 / degree, points, 4);
    gdImageFilledPolygon(img, points, 4, black);
    // 長方形旋轉到左上方
    rotatePoints(center_x, center_y, -2 * rot_ang2 / degree, points, 4);
    gdImageFilledPolygon(img, points, 4, black);
    // 長方形旋轉到下右方
    rotatePoints(center_x, center_y, -2 * rot_ang / degree, points, 4);
    gdImageFilledPolygon(img, points, 4, black);
    // 長方形旋轉到下左方
    rotatePoints(center_x, center_y, -2 * rot_ang2 / degree, points, 4);
    gdImageFilledPolygon(img, points, 4, black);

    // 繪製大圓形的輪廓
    int circle_radius = (int)(height * 2.0 / 5.0);
    gdImageEllipse(img, center_x, center_y, big_circle_dia, big_circle_dia, black);
    // 左小圓
    gdImageEllipse(img, left_center_x, left_center_y, small_circle_dia, small_circle_dia, red);
    // 右小圓
  gdImageEllipse(img, right_center_x, right_center_y, small_circle_dia, small_circle_dia, blue);
gdImageFill(img, left_center_x, left_center_y, red); // 用紅色填充左小圓
gdImageFill(img, right_center_x, right_center_y - small_circle_dia / 2 - 10, red);
gdImageFill(img, right_center_x, right_center_y, blue); // 用藍色填充右小圓
gdImageFill(img, left_center_x, left_center_y + small_circle_dia / 2 + 10, blue);

gdImageEllipse(img, center_x, center_y, big_circle_dia, big_circle_dia, white);

{
    int lineWidth = 19;  // 線的寬度

    // 繪製線段
    gdImageSetThickness(img, lineWidth);
    gdImageLine(img, 423, 80, 263, 320, white);
    gdImageLine(img, 363, 80, 203, 320, white);
    gdImageLine(img, 777, 80, 937, 320, white);
    gdImageLine(img, 837, 80, 997, 320, white);
    gdImageLine(img, 960, 160, 825, 250, white);
    gdImageLine(img, 997, 480, 837, 720, white);
    gdImageLine(img, 937, 480, 777, 720, white);
    gdImageLine(img, 825, 550, 960, 640, white);
    gdImageLine(img, 263, 480, 423, 720, white);
    gdImageLine(img, 203, 480, 363, 720, white);
    gdImageLine(img, 285, 610, 327, 582, white);
}
{
    int lineWidth = 31;
    gdImageSetThickness(img, lineWidth);
    gdImageLine(img, 852, 150, 920, 250, black);
}
}