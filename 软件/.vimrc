inoremap { {<CR>}<esc>ko
inoremap [ []<esc>i
inoremap ( ()<esc>i
inoremap " ""<esc>i
inoremap ' ''<esc>i
set tabstop=4
set softtabstop=4
set shiftwidth=4
set mouse=a
set number
nnoremap <F9> :call CompileRunGcc()<CR>
func! CompileRunGcc()
    exec "w"
	exec '!cd ./'
    exec '!g++ % -o %<'
    exec '!time ./%<'
    endfunc
colorscheme slate
