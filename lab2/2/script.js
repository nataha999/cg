document.addEventListener('DOMContentLoaded', function () {
    const canvas = document.getElementById('canvas');
    const context = canvas.getContext('2d');
    let isDrawing = false;

    context.lineWidth = 2;
    context.lineCap = 'round';
    context.strokeStyle = '#000';
// при смене окна не залипала мышь и драгндроп перестал работать
//изображение сохраняет пропорции
    function draw(e) {
        if (!isDrawing) {
            return;
        }

        context.lineTo(e.clientX - canvas.offsetLeft, e.clientY - canvas.offsetTop);
        context.stroke();
        context.beginPath();
        context.moveTo(e.clientX - canvas.offsetLeft, e.clientY - canvas.offsetTop);
    }

    canvas.addEventListener('mousedown', startDrawing);
    canvas.addEventListener('mousemove', draw);
    canvas.addEventListener('mouseup', stopDrawing);

    function startDrawing(e) {
        isDrawing = true;
        draw(e);
    }

    function stopDrawing() {
        isDrawing = false;
        context.beginPath();
    }

    function clearDrawing() {
        context.clearRect(0, 0, canvas.width, canvas.height);
    }

    document.querySelector('#new-button').addEventListener('click', clearDrawing);

    function openImage() {
        const fileInput = document.getElementById('fileInput');
        fileInput.addEventListener('change', function (e) {
            const file = e.target.files[0];
            const reader = new FileReader();
            reader.onload = function (event) {
                const img = new Image();
                img.onload = function () {
                    clearDrawing();
                    context.drawImage(img, 0, 0, canvas.width, canvas.height);
                };
                img.src = event.target.result;
            };
            reader.readAsDataURL(file);
        });
        fileInput.click();
    }

    document.querySelector('#open-button').addEventListener('click', openImage);

    function saveImage(format) {
        const dataURL = canvas.toDataURL(`image/${format}`);
        const a = document.createElement('a'); 
        a.href = dataURL;
        a.download = `drawing.${format}`;
    }

    document.getElementById('save-button').addEventListener('change', function(){
        const selectedItem = this.value;
        saveImage(selectedItem);
    });

    document.getElementById('colorPicker').addEventListener('change', function () {
        context.strokeStyle = this.value;
    });
});