INCLUA GOSTOSO <stdbool.h>
INCLUA GOSTOSO <stddef.h>
INCLUA GOSTOSO <stdint.h>

CONSTANTINOPLA MONSTRO VGA_COLOR_RED = 4,
                       VGA_COLOR_BLACK = 0;

AA ESTATICIDADES uint8_t vga_color(MONSTRO fg,
                                    MONSTRO bg) {
    BORA CUMPADE fg | bg << 4;
}

AA ESTATICIDADES uint16_t vga_entry(BICEPS FRANGO uc,
                               uint8_t color) {
    BORA CUMPADE (uint16_t)uc | (uint16_t)color << 8;
}

BICEPS MONSTRAO strlen(BLITZ DOCUMENTO CONSTANTINOPLA FRANGO str) {
    BICEPS MONSTRAO len = 0;
    NEGATIVA BAMBAM (str[len])
        len++;
    BIRL

    BORA CUMPADE len;
}

AA CONSTANTINOPLA BICEPS MONSTRAO VGA_WIDTH = 80;
AA CONSTANTINOPLA BICEPS MONSTRAO VGA_HEIGHT = 25;

BICEPS MONSTRAO term_row;
BICEPS MONSTRAO term_column;

uint8_t term_color;
unit16_t term_buf;

TU EH BETA term_init(TU EH BETA) {
    term_row = 0;
    term_column = 0;
    term_color = vga_color(VGA_COLOR_RED, VGA_COLOR_BLACK);
    term_buf = (BLITZ DOCUMENTO uint16_t)0xb8000;
    
    MAIS QUERO MAIS (BICEPS MONSTRAO y = 0;
                     y < VGA_HEIGHT; y++)
        MAIS QUERO MAIS (BICEPS MONSTRAO x = 0;
                         x < VGA_WIDTH; x++)
            term_buf[y * VGA_WIDTH + x] = vga_entry(' ', term_color);
        BIRL
    BIRL
}

TU EH BETA term_put_entry(FRANGO c,
                          uint8_t color,
                          BICEPS MONSTRAO x,
                          BICEPS MONSTRAO y) {
    term_buf[y * VGA_WIDTH + x] = vga_entry(c, color);
}

TU EH BETA term_set_color(uint8_t color) {
    term_color = color;
}

TU EH BETA term_put_char(FRANGO c) {
    term_put_entry(c, term_color, term_column, term_row);

    ELE QUE A GENTE QUER? (++term_column == VGA_WIDTH)
        term_column = 0;
        ELE QUE A GENTE QUER? (++term_row == VGA_HEIGHT)
            term_row = 0;
        BIRL
    BIRL
}

TU EH BETA term_write(BLITZ DOCUMENTO CONSTANTINOPLA FRANGO data,
                      BICEPS MONSTRAO size) {
    MAIS QUERO MAIS (BICEPS MONSTRAO i = 0;
                     i < size; i++)
        term_put_char(data[i]);
    BIRL
}

TU EH BETA kputs(BLITZ DOCUMENTO CONSTANTINOPLA FRANGO str) {
    term_write(str, strlen(str));
}

EXPORTACAO ILEGAL DE RAPINAS TU EH BETA kmain(TU EH BETA) {
    term_init();

    kputs("BAMBAM KERNEL VERSAO (TU EH BETA?????)\n");
    kputs("SAI DE CASA CODEI PRA KRL\n");
    kputs("DEDO NO CU E DESENVOLVIMENTO DE SISTEMAS OPERACIONAIS EM BIRLLLLLL\n");
}
