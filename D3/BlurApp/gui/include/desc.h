#pragma once

#include <QImage>

/// @brief Применяет к изображению эффект размытия (box blur)
/// @param source Исходное изображение
/// @param blurRadius Радиус размытия (0 — без эффекта)
/// @return Новое изображение с применённым эффектом
QImage blurImage(QImage source, int blurRadius);
