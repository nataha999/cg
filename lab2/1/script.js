const fileInput = document.getElementById('file')
const imageContainer = document.getElementById('image-container')

if (fileInput && imageContainer) {
    fileInput.addEventListener('change', (e) => {
        for (const imageMetadata of e.target.files) {
            const image = new Image(imageMetadata)
            imageContainer.appendChild(image.imageElement)
        }
    })
}
// при смене окна не залипала мышь и драгндроп перестал работать
class Image {
    constructor(imageMetadata) {
        this.imageElement = document.createElement('img')
        this.imageElement.src = URL.createObjectURL(imageMetadata)
        this.imageElement.draggable = false
        this.imageElement.style.position = 'absolute'

        this.dragStartX = 0
        this.dragStartY = 0
        this.isDragging = false

        this.setPosition(10, 10)

        this.imageElement.addEventListener('mousedown', this.onMouseDown)
        document.addEventListener('mousemove', this.onMouseMove)
        document.addEventListener('mouseup', this.onMouseUp)
    }

    onMouseDown = (event) => {
        this.dragStartX = event.clientX - this.x
        this.dragStartY = event.clientY - this.y
        this.isDragging = true
    }

    onMouseMove = (event) => {
        if (!this.isDragging) return
        this.setPosition(event.clientX - this.dragStartX, event.clientY - this.dragStartY)
    }

    onMouseUp = () => {
        this.isDragging = false
    }

    setPosition(x, y) {
        this.x = x
        this.y = y
        this.imageElement.style.left = x + 'px'
        this.imageElement.style.top = y + 'px'
    }
}