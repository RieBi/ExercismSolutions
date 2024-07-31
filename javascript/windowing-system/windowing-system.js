// @ts-check

/**
 * Implement the classes etc. that are needed to solve the
 * exercise in this file. Do not forget to export the entities
 * you defined so they are available for the tests.
 */

export function Size(width = 80, height = 60) {
    this.width = width;
    this.height = height;
}

Size.prototype.resize = function(newWidth, newHeight) {
    this.width = newWidth;
    this.height = newHeight;
}

export function Position(x = 0, y = 0) {
    this.x = x;
    this.y = y;
}

Position.prototype.move = function(newX, newY) {
    this.x = newX;
    this.y = newY;
}

export class ProgramWindow {
    constructor() {
        this._screenSize = new Size(800, 600);
        this.size = new Size();
        this.position = new Position();
    }

    get screenSize() {
        return this._screenSize;
    }

    /**
     * Resizes window to the specified size.
     * @param {Size} size 
     */
    resize(size) {
        if (size.height < 1) {
            size.height = 1;
        } else if (size.height + this.position.y > this._screenSize.height) {
            size.height = this._screenSize.height - this.position.y;
        }
        if (size.width < 1) {
            size.width = 1;
        } else if (size.width + this.position.x > this._screenSize.width) {
            size.width = this._screenSize.width - this.position.x;
        }
        
        this.size.height = size.height;
        this.size.width = size.width;
    }

    /**
     * Moves window to the specified position.
     * @param {Position} position 
     */
    move(position) {
        if (position.x < 0) {
            position.x = 0;
        } else if (position.x + this.size.width > this._screenSize.width) {
            position.x = this._screenSize.width - this.size.width;
        }
        if (position.y < 0) {
            position.y = 0;
        } else if (position.y + this.size.height > this._screenSize.height) {
            position.y = this._screenSize.height - this.size.height;
        }

        this.position.x = position.x;
        this.position.y = position.y;
    }
}

const changeSizeWidth = 400;
const changeSizeHeight = 300;
const changePositionX = 100;
const changePositionY = 150;

/**
 * 
 * @param {ProgramWindow} window 
 */
export function changeWindow(window) {
    window.resize(new Size(changeSizeWidth, changeSizeHeight));
    window.move(new Position(changePositionX, changePositionY));
    return window;
}