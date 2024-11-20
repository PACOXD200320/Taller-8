void Menu(char Productos[5][50], float TiempoYPrecio[2][5], float *tiempoRestante, float *dineroRestante);
void ListadoProductos(char Productos[5][50], float TiempoYPrecio[2][5]);
void CambiarProducto(char Productos[5][50], float TiempoYPrecio[2][5]);
void CambiarPrecio(char Productos[5][50], float TiempoYPrecio[2][5]); // Corregido para incluir Productos
void CambiarTiempo(char Productos[5][50], float TiempoYPrecio[2][5]);
void EliminarProducto(char Productos[5][50], float TiempoYPrecio[2][5]);
void RealizarPedido(char Productos[5][50], float TiempoYPrecio[2][5], float *tiempoRestante, float *dineroRestante) ;