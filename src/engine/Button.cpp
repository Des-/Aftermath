//      Button.cpp -- A button widget.
//
//      Copyright 2011 Kevin Harrison <keharriso@gmail.com>
//
//      This file is part of Aftermath.
//
//      Aftermath is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//
//      Aftermath is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with Aftermath.  If not, see <http://www.gnu.org/licenses/>

#include "Button.hpp"

using namespace Aftermath::Engine;

Button::Button(sf::Sprite * upImage, sf::Sprite * overImage,
        sf::Sprite * downImage, sf::Text * text, float x, float y,
        float width, float height, void (*callback)(Widget *),
        bool fitText, bool fitToText) : mText(text), mUp(upImage),
        mOver(overImage), mDown(downImage), mCallback(callback) {
    setPosition(x, y);

    if (width >= 0) setWidth(width);
    else setWidth(upImage->GetSize().x);

    if (height >= 0) setHeight(height);
    else setHeight(upImage->GetSize().y);

    if (fitToText) this->fitToText();
    else if (fitText) this->fitText();
}

Button::~Button() {
    delete mText;
    delete mUp;
    delete mOver;
    delete mDown;
}

void Button::fitToText(int textOffset) {
    if (mText != NULL) {
        textOffset *= 2;
        sf::FloatRect trect = mText->GetRect();
        setSize(trect.Width + textOffset, trect.Height + textOffset);
    }
}

void Button::fitText(int textOffset) {
    if (mText != NULL) {
        textOffset *= 2;
        sf::FloatRect trect = mText->GetRect();
        mText->Scale((getWidth() - textOffset) / trect.Width,
                     (getHeight() - textOffset) / trect.Height);
    }
}

void Button::setCallback(void (*callback)(Widget *)) {
    mCallback = callback;
}

void Button::mouseButtonReleased(sf::Mouse::Button button, int x, int y) {
    if (mCallback != NULL && isMouseFocused()) (*mCallback)(this);
}

void Button::draw(sf::RenderWindow & window) {
    // Draw image
    if (isMousePressing()) {
        mDown->SetPosition(getX(), getY());
        mDown->Resize(getWidth(), getHeight());
        window.Draw(*mDown);
    } else if (isMouseOver()) {
        mOver->SetPosition(getX(), getY());
        mOver->Resize(getWidth(), getHeight());
        window.Draw(*mOver);
    } else {
        mUp->SetPosition(getX(), getY());
        mUp->Resize(getWidth(), getHeight());
        window.Draw(*mUp);
    }

    // Draw text
    if (mText != NULL) {
        const sf::FloatRect & trect = mText->GetRect();
        mText->SetPosition(getX() + (getWidth() - trect.Width) / 2,
                           getY() + (getHeight() - trect.Height) / 2 - 3);
        window.Draw(*mText);
    }
}

bool Button::contains(float x, float y) const {
    const sf::Vector2f & picScale = mUp->GetScale();
    return Widget::contains(x, y) &&
        mUp->GetPixel(
            (x - getX()) / picScale.x, (y - getY()) / picScale.y
        ).a > 0;
}
