#include "rna_transcription.h"

char *to_rna(const char *dna)
{
    int length = strlen(dna);

    char *rna = malloc(length);
    while (*dna != '\0') {
        char cur = *dna;
        char complement =
            cur == 'G' ? 'C' :
            cur == 'C' ? 'G' :
            cur == 'T' ? 'A' :
            cur == 'A' ? 'U'
            : '\0';

        *rna = complement;
        dna++;
        rna++;
    }

    *rna = '\0';

    return rna - length;
}
