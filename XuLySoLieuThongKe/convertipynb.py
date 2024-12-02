import json

def convert_ipynb_to_text(ipynb_file, output_file):
    with open(ipynb_file, 'r', encoding='utf-8') as f:
        notebook = json.load(f)

    with open(output_file, 'w', encoding='utf-8') as f:
        for cell in notebook['cells']:
            if cell['cell_type'] == 'markdown':
                f.write(''.join(cell['source']) + '\n')
            elif cell['cell_type'] == 'code':
                f.write('\n```{r}\n')
                f.write(''.join(cell['source']))
                f.write('\n```\n\n')

# Usage
convert_ipynb_to_text('NOTE_LinearReg.ipynb', 'output.rmd')