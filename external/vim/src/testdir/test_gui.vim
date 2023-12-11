" Tests specifically for the GUI

source shared.vim
source check.vim
CheckCanRunGui

source setup_gui.vim

func Setup()
  call GUISetUpCommon()
endfunc

func TearDown()
  call GUITearDownCommon()
endfunc

" Test for resetting "secure" flag after GUI has started.
" Must be run first, since it starts the GUI on Unix.
func Test_1_set_secure()
  set exrc secure
  gui -f
  call assert_equal(1, has('gui_running'))
endfunc

" As for non-GUI, a balloon_show() test was already added with patch 8.0.0401
func Test_balloon_show()
  CheckFeature balloon_eval
  " This won't do anything but must not crash either.
  call balloon_show('hi!')
endfunc

func Test_colorscheme()
  call assert_equal('16777216', &t_Co)

  let colorscheme_saved = exists('g:colors_name') ? g:colors_name : 'default'
  let g:color_count = 0
  augroup TestColors
    au!
    au ColorScheme * let g:color_count += 1| let g:after_colors = g:color_count
    au ColorSchemePre * let g:color_count += 1 |let g:before_colors = g:color_count
  augroup END

  colorscheme torte
  redraw!
  call assert_equal('dark', &background)
  call assert_equal(1, g:before_colors)
  call assert_equal(2, g:after_colors)
  call assert_equal("\ntorte", execute('colorscheme'))

  let a = substitute(execute('hi Search'), "\n\\s\\+", ' ', 'g')
  call assert_match("\nSearch         xxx term=reverse ctermfg=0 ctermbg=12 gui=bold guifg=Black guibg=Red", a)

  call assert_fails('colorscheme does_not_exist', 'E185:')

  exec 'colorscheme' colorscheme_saved
  augroup TestColors
    au!
  augroup END
  unlet g:color_count g:after_colors g:before_colors
  redraw!
endfunc

func Test_getfontname_with_arg()
  CheckX11BasedGui

  if has('gui_athena') || has('gui_motif')
    " Invalid font name. The result should be an empty string.
    call assert_equal('', getfontname('notexist'))

    " Valid font name. This is usually the real name of 7x13 by default.
    let fname = '-Misc-Fixed-Medium-R-Normal--13-120-75-75-C-70-ISO8859-1'
    call assert_match(fname, getfontname(fname))

  elseif has('gui_gtk2') || has('gui_gnome') || has('gui_gtk3')
    " Invalid font name. The result should be the name plus the default size.
    call assert_equal('notexist 10', getfontname('notexist'))
    call assert_equal('', getfontname('*'))

    " Valid font name. This is usually the real name of Monospace by default.
    let fname = 'Bitstream Vera Sans Mono 12'
    call assert_equal(fname, getfontname(fname))
  endif
endfunc

func Test_getfontname_without_arg()
  CheckX11BasedGui

  let fname = getfontname()

  if has('gui_kde')
    " 'expected' is the value specified by SetUp() above.
    call assert_equal('Courier 10 Pitch/8/-1/5/50/0/0/0/0/0', fname)
  elseif has('gui_athena') || has('gui_motif')
    " 'expected' is DFLT_FONT of gui_x11.c or its real name.
    let pat = '\(7x13\)\|\(\c-Misc-Fixed-Medium-R-Normal--13-120-75-75-C-70-ISO8859-1\)'
    call assert_match(pat, fname)
  elseif has('gui_gtk2') || has('gui_gnome') || has('gui_gtk3')
    " 'expected' is DEFAULT_FONT of gui_gtk_x11.c.
    call assert_equal('Monospace 10', fname)
  endif
endfunc

func Test_getwinpos()
  call assert_match('Window position: X \d\+, Y \d\+', execute('winpos'))
  call assert_true(getwinposx() >= 0)
  call assert_true(getwinposy() >= 0)
  call assert_equal([getwinposx(), getwinposy()], getwinpos())
endfunc

func Test_quoteplus()
  CheckX11BasedGui

  let g:test_is_flaky = 1

  let quoteplus_saved = @+

  let test_call     = 'Can you hear me?'
  let test_response = 'Yes, I can.'
  let vim_exe = GetVimCommand()
  let testee = 'VIMRUNTIME=' . $VIMRUNTIME . '; export VIMRUNTIME;'
        \ . vim_exe . ' --noplugin --not-a-term -c ''%s'''
  " Ignore the "failed to create input context" error.
  let cmd = 'call test_ignore_error("E285") | '
        \ . 'gui -f | '
        \ . 'call feedkeys("'
        \ . '\"+p'
        \ . ':s/' . test_call . '/' . test_response . '/\<CR>'
        \ . '\"+yis'
        \ . ':q!\<CR>", "tx")'
  let run_vimtest = printf(testee, cmd)

  " Set the quoteplus register to test_call, and another gvim will launched.
  " Then, it first tries to paste the content of its own quotedplus register
  " onto it.  Second, it tries to substitute test_response for the pasted
  " sentence.  If the sentence is identical to test_call, the substitution
  " should succeed.  Third, it tries to yank the result of the substitution
  " to its own quoteplus register, and last it quits.  When system()
  " returns, the content of the quoteplus register should be identical to
  " test_response if those quoteplus registers are synchronized properly
  " with/through the X11 clipboard.
  let @+ = test_call
  call system(run_vimtest)
  call assert_equal(test_response, @+)

  let @+ = quoteplus_saved
endfunc

func Test_gui_read_stdin()
  CheckUnix

  call writefile(['some', 'lines'], 'Xstdin')
  let script =<< trim END
      call writefile(getline(1, '$'), 'XstdinOK')
      qa!
  END
  call writefile(script, 'Xscript')

  " Cannot use --not-a-term here, the "reading from stdin" message would not be
  " displayed.
  let vimcmd = substitute(GetVimCommand(), '--not-a-term', '', '')

  call system('cat Xstdin | ' .. vimcmd .. ' -f -g -S Xscript -')
  call assert_equal(['some', 'lines'], readfile('XstdinOK'))

  call delete('Xstdin')
  call delete('XstdinOK')
  call delete('Xscript')
endfunc

func Test_set_background()
  let background_saved = &background

  set background&
  call assert_equal('light', &background)

  set background=dark
  call assert_equal('dark', &background)

  let &background = background_saved
endfunc

func Test_set_balloondelay()
  CheckOption balloondelay

  let balloondelay_saved = &balloondelay

  " Check if the default value is identical to that described in the manual.
  set balloondelay&
  call assert_equal(600, &balloondelay)

  " Edge cases

  " XXX This fact should be hidden so that people won't be tempted to write
  " plugin/TimeMachine.vim.  TODO Add reasonable range checks to the source
  " code.
  set balloondelay=-1
  call assert_equal(-1, &balloondelay)

  " Though it's possible to interpret the zero delay to be 'as soon as
  " possible' or even 'indefinite', its actual meaning depends on the GUI
  " toolkit in use after all.
  set balloondelay=0
  call assert_equal(0, &balloondelay)

  set balloondelay=1
  call assert_equal(1, &balloondelay)

  " Since p_bdelay is of type long currently, the upper bound can be
  " impractically huge and machine-dependent.  Practically, it's sufficient
  " to check if balloondelay works with 0x7fffffff (32 bits) for now.
  set balloondelay=2147483647
  call assert_equal(2147483647, &balloondelay)

  let &balloondelay = balloondelay_saved
endfunc

func Test_set_ballooneval()
  CheckOption ballooneval

  let ballooneval_saved = &ballooneval

  set ballooneval&
  call assert_equal(0, &ballooneval)

  set ballooneval
  call assert_notequal(0, &ballooneval)

  set noballooneval
  call assert_equal(0, &ballooneval)

  let &ballooneval = ballooneval_saved
endfunc

func Test_set_balloonexpr()
  CheckOption balloonexpr

  let balloonexpr_saved = &balloonexpr

  " Default value
  set balloonexpr&
  call assert_equal('', &balloonexpr)

  " User-defined function
  new
  func MyBalloonExpr()
      return 'Cursor is at line ' . v:beval_lnum .
	      \', column ' . v:beval_col .
	      \ ' of file ' .  bufname(v:beval_bufnr) .
	      \ ' on word "' . v:beval_text . '"' .
	      \ ' in window ' . v:beval_winid . ' (#' . v:beval_winnr . ')'
  endfunc
  setl balloonexpr=MyBalloonExpr()
  setl ballooneval
  call assert_equal('MyBalloonExpr()', &balloonexpr)
  " TODO Read non-empty text, place the pointer at a character of a word,
  " and check if the content of the balloon is the same as what is expected.
  " Also, check if textlock works as expected.
  setl balloonexpr&
  call assert_equal('', &balloonexpr)
  delfunc MyBalloonExpr

  " Using a script-local function
  func s:NewBalloonExpr()
  endfunc
  set balloonexpr=s:NewBalloonExpr()
  call assert_equal(expand('<SID>') .. 'NewBalloonExpr()', &balloonexpr)
  set balloonexpr=<SID>NewBalloonExpr()
  call assert_equal(expand('<SID>') .. 'NewBalloonExpr()', &balloonexpr)
  delfunc s:NewBalloonExpr
  bwipe!

  " Multiline support
  if has('balloon_multiline')
    " Multiline balloon using NL
    new
    func MyBalloonFuncForMultilineUsingNL()
      return "Multiline\nSuppported\nBalloon\nusing NL"
    endfunc
    setl balloonexpr=MyBalloonFuncForMultilineUsingNL()
    setl ballooneval
    call assert_equal('MyBalloonFuncForMultilineUsingNL()', &balloonexpr)
    " TODO Read non-empty text, place the pointer at a character of a word,
    " and check if the content of the balloon is the same as what is
    " expected.  Also, check if textlock works as expected.
    setl balloonexpr&
    delfunc MyBalloonFuncForMultilineUsingNL
    bwipe!

    " Multiline balloon using List
    new
    func MyBalloonFuncForMultilineUsingList()
      return [ 'Multiline', 'Suppported', 'Balloon', 'using List' ]
    endfunc
    setl balloonexpr=MyBalloonFuncForMultilineUsingList()
    setl ballooneval
    call assert_equal('MyBalloonFuncForMultilineUsingList()', &balloonexpr)
    " TODO Read non-empty text, place the pointer at a character of a word,
    " and check if the content of the balloon is the same as what is
    " expected.  Also, check if textlock works as expected.
    setl balloonexpr&
    delfunc MyBalloonFuncForMultilineUsingList
    bwipe!
  endif

  let &balloonexpr = balloonexpr_saved
endfunc

" Invalid arguments are tested with test_options in conjunction with segfaults
" caused by them (Patch 8.0.0357, 24922ec233).
func Test_set_guicursor()
  let guicursor_saved = &guicursor

  let default = [
        \ "n-v-c:block-Cursor/lCursor",
        \ "ve:ver35-Cursor",
        \ "o:hor50-Cursor",
        \ "i-ci:ver25-Cursor/lCursor",
        \ "r-cr:hor20-Cursor/lCursor",
        \ "sm:block-Cursor-blinkwait175-blinkoff150-blinkon175"
        \ ]

  " Default Value
  set guicursor&
  call assert_equal(join(default, ','), &guicursor)

  " Argument List Example 1
  let opt_list = copy(default)
  let opt_list[0] = "n-c-v:block-nCursor"
  exec "set guicursor=" . join(opt_list, ',')
  call assert_equal(join(opt_list, ','), &guicursor)
  unlet opt_list

  " Argument List Example 2
  let opt_list = copy(default)
  let opt_list[3] = "i-ci:ver30-iCursor-blinkwait300-blinkon200-blinkoff150"
  exec "set guicursor=" . join(opt_list, ',')
  call assert_equal(join(opt_list, ','), &guicursor)
  unlet opt_list

  " 'a' Mode
  set guicursor&
  let &guicursor .= ',a:blinkon0'
  call assert_equal(join(default, ',') . ",a:blinkon0", &guicursor)

  let &guicursor = guicursor_saved
endfunc

func Test_set_guifont_errors()
  if has('win32')
    " Invalid font names are accepted in GTK GUI
    call assert_fails('set guifont=xa1bc23d7f', 'E596:')
  endif

  " This only works if 'renderoptions' exists and does not work for Windows XP
  " and older.
  if exists('+renderoptions') && windowsversion() !~ '^[345]\.'
    " doing this four times used to cause a crash
    set renderoptions=type:directx
    for i in range(5)
      set guifont=
    endfor
    set renderoptions=
    for i in range(5)
      set guifont=
    endfor
  endif
endfunc

func Test_set_guifont()
  CheckX11BasedGui

  let guifont_saved = &guifont
  if has('xfontset')
    " Prevent 'guifontset' from canceling 'guifont'.
    let guifontset_saved = &guifontset
    set guifontset=
  endif

  if has('gui_athena') || has('gui_motif')
    " Non-empty font list with invalid font names.
    "
    " This test is twofold: (1) It checks if the command fails as expected
    " when there are no loadable fonts found in the list. (2) It checks if
    " 'guifont' remains the same after the command loads none of the fonts
    " listed.
    let flist = &guifont
    call assert_fails('set guifont=-notexist1-*,-notexist2-*')
    call assert_equal(flist, &guifont)

    " Non-empty font list with a valid font name.  Should pick up the first
    " valid font.
    set guifont=-notexist1-*,fixed,-notexist2-*
    let pat = '\(fixed\)\|\(\c-Misc-Fixed-Medium-R-SemiCondensed--13-120-75-75-C-60-ISO8859-1\)'
    call assert_match(pat, getfontname())

    " Empty list. Should fallback to the built-in default.
    set guifont=
    let pat = '\(7x13\)\|\(\c-Misc-Fixed-Medium-R-Normal--13-120-75-75-C-70-ISO8859-1\)'
    call assert_match(pat, getfontname())

  elseif has('gui_gtk2') || has('gui_gnome') || has('gui_gtk3')
    " For GTK, what we refer to as 'font names' in our manual are actually
    " 'initial font patterns'.  A valid font which matches the 'canonical font
    " pattern' constructed from a given 'initial pattern' is to be looked up
    " and loaded.  That explains why the GTK GUIs appear to accept 'invalid
    " font names'.
    "
    " Non-empty list.  Should always pick up the first element, no matter how
    " strange it is, as explained above.
    set guifont=(´・ω・｀)\ 12,Courier\ 12
    call assert_equal('(´・ω・｀) 12', getfontname())

    " Empty list. Should fallback to the built-in default.
    set guifont=
    call assert_equal('Monospace 10', getfontname())
  endif

  if has('xfontset')
    let &guifontset = guifontset_saved
  endif
  let &guifont = guifont_saved
endfunc

func Test_set_guifontset()
  CheckFeature xfontset
  let skipped = ''

  call assert_fails('set guifontset=*', 'E597:')

  let ctype_saved = v:ctype

  " First, since XCreateFontSet(3) is very sensitive to locale, fonts must
  " be chosen meticulously.
  let font_head = '-misc-fixed-medium-r-normal--14'

  let font_aw70 = font_head . '-130-75-75-c-70'
  let font_aw140 = font_head . '-130-75-75-c-140'

  let font_jisx0201 = font_aw70 . '-jisx0201.1976-0'
  let font_jisx0208 = font_aw140 . '-jisx0208.1983-0'

  let full_XLFDs = join([ font_jisx0208, font_jisx0201 ], ',')
  let short_XLFDs = join([ font_aw140, font_aw70 ], ',')
  let singleton = font_head . '-*'
  let aliases = 'k14,r14'

  " Second, among 'locales', look up such a locale that gets 'set
  " guifontset=' to work successfully with every fontset specified with
  " 'fontsets'.
  let locales = [ 'ja_JP.UTF-8', 'ja_JP.eucJP', 'ja_JP.SJIS' ]
  let fontsets = [ full_XLFDs, short_XLFDs, singleton, aliases ]

  let feasible = 0
  for locale in locales
    try
      exec 'language ctype' locale
    catch /^Vim\%((\a\+)\)\=:E197/
      continue
    endtry
    let done = 0
    for fontset in fontsets
      try
	exec 'set guifontset=' . fontset
      catch /^Vim\%((\a\+)\)\=:E\%(250\|252\|234\|597\|598\)/
	break
      endtry
      let done += 1
    endfor
    if done == len(fontsets)
      let feasible = 1
      break
    endif
  endfor

  " Third, give a set of tests if it is found feasible.
  if !feasible
    let skipped = g:not_hosted
  else
    " N.B. 'v:ctype' has already been set to an appropriate value in the
    " previous loop.
    for fontset in fontsets
      exec 'set guifontset=' . fontset
      call assert_equal(fontset, &guifontset)
    endfor
  endif

  " Finally, restore ctype.
  exec 'language ctype' ctype_saved

  if !empty(skipped)
    throw skipped
  endif
endfunc

func Test_set_guifontwide()
  CheckX11BasedGui

  call assert_fails('set guifontwide=*', 'E533:')

  if has('gui_gtk')
    let guifont_saved = &guifont
    let guifontwide_saved = &guifontwide

    let fc_match = exepath('fc-match')
    if empty(fc_match)
      let skipped = g:not_hosted
    else
      let &guifont = system('fc-match -f "%{family[0]} %{size}" monospace:size=10:lang=en')
      let wide = system('fc-match -f "%{family[0]} %{size}" monospace:size=10:lang=ja')
      exec 'set guifontwide=' . fnameescape(wide)
      call assert_equal(wide, &guifontwide)
    endif

    let &guifontwide = guifontwide_saved
    let &guifont = guifont_saved

  elseif has('gui_athena') || has('gui_motif')
    " guifontwide is premised upon the xfontset feature.
    if !has('xfontset')
      let skipped = g:not_supported . 'xfontset'
    else
      let encoding_saved    = &encoding
      let guifont_saved     = &guifont
      let guifontset_saved  = &guifontset
      let guifontwide_saved = &guifontwide

      let nfont = '-misc-fixed-medium-r-normal-*-18-120-100-100-c-90-iso10646-1'
      let wfont = '-misc-fixed-medium-r-normal-*-18-120-100-100-c-180-iso10646-1'

      set encoding=utf-8

      " Case 1: guifontset is empty
      set guifontset=

      " Case 1-1: Automatic selection
      set guifontwide=
      exec 'set guifont=' . nfont
      call assert_equal(wfont, &guifontwide)

      " Case 1-2: Manual selection
      exec 'set guifontwide=' . wfont
      exec 'set guifont=' . nfont
      call assert_equal(wfont, &guifontwide)

      " Case 2: guifontset is invalid
      try
        set guifontset=-*-notexist-*
        call assert_report("'set guifontset=-*-notexist-*' should have failed")
      catch
        call assert_exception('E598:')
      endtry
      " Set it to an invalid value brutally for preparation.
      let &guifontset = '-*-notexist-*'

      " Case 2-1: Automatic selection
      set guifontwide=
      exec 'set guifont=' . nfont
      call assert_equal(wfont, &guifontwide)

      " Case 2-2: Manual selection
      exec 'set guifontwide=' . wfont
      exec 'set guifont=' . nfont
      call assert_equal(wfont, &guifontwide)

      let &guifontwide = guifontwide_saved
      let &guifontset  = guifontset_saved
      let &guifont     = guifont_saved
      let &encoding    = encoding_saved
    endif
  endif
endfunc

func Test_set_guiligatures()
  CheckX11BasedGui

  if has('gui_gtk') || has('gui_gtk2') || has('gui_gnome') || has('gui_gtk3')
    " Try correct value
    set guiligatures=<>=ab
    call assert_equal("<>=ab", &guiligatures)
    " Try to throw error
    try
      set guiligatures=<>=šab
      call assert_report("'set guiligatures=<>=šab should have failed")
    catch
      call assert_exception('E1243:')
    endtry
  endif
endfunc

func Test_set_guiheadroom()
  CheckX11BasedGui

  " Since this script is to be read together with '-U NONE', the default
  " value must be preserved.
  call assert_equal(50, &guiheadroom)
endfunc

func Test_set_guioptions()
  let guioptions_saved = &guioptions
  let duration = '200m'

  if has('win32')
    " Default Value
    set guioptions&
    call assert_equal('egmrLtT', &guioptions)

  else
    " Default Value
    set guioptions&
    call assert_equal('aegimrLtT', &guioptions)

    " To activate scrollbars of type 'L' or 'R'.
    wincmd v
    redraw!

    " Remove all default GUI ornaments
    set guioptions-=T
    exec 'sleep' . duration
    call assert_equal('aegimrLt', &guioptions)
    set guioptions-=t
    exec 'sleep' . duration
    call assert_equal('aegimrL', &guioptions)
    set guioptions-=L
    exec 'sleep' . duration
    call assert_equal('aegimr', &guioptions)
    set guioptions-=r
    exec 'sleep' . duration
    call assert_equal('aegim', &guioptions)
    set guioptions-=m
    exec 'sleep' . duration
    call assert_equal('aegi', &guioptions)

    " Try non-default GUI ornaments
    set guioptions+=l
    exec 'sleep' . duration
    call assert_equal('aegil', &guioptions)
    set guioptions-=l
    exec 'sleep' . duration
    call assert_equal('aegi', &guioptions)

    set guioptions+=R
    exec 'sleep' . duration
    call assert_equal('aegiR', &guioptions)
    set guioptions-=R
    exec 'sleep' . duration
    call assert_equal('aegi', &guioptions)

    set guioptions+=b
    exec 'sleep' . duration
    call assert_equal('aegib', &guioptions)
    set guioptions+=h
    exec 'sleep' . duration
    call assert_equal('aegibh', &guioptions)
    set guioptions-=h
    exec 'sleep' . duration
    call assert_equal('aegib', &guioptions)
    set guioptions-=b
    exec 'sleep' . duration
    call assert_equal('aegi', &guioptions)

    set guioptions+=v
    exec 'sleep' . duration
    call assert_equal('aegiv', &guioptions)
    set guioptions-=v
    exec 'sleep' . duration
    call assert_equal('aegi', &guioptions)

    if has('gui_motif')
      set guioptions+=F
      exec 'sleep' . duration
      call assert_equal('aegiF', &guioptions)
      set guioptions-=F
      exec 'sleep' . duration
      call assert_equal('aegi', &guioptions)
    endif

    if has('gui_gtk3')
      set guioptions+=d
      exec 'sleep' . duration
      call assert_equal('aegid', &guioptions)
      set guioptions-=d
      exec 'sleep' . duration
      call assert_equal('aegi', &guioptions)
    endif

    " Restore GUI ornaments to the default state.
    set guioptions+=m
    exec 'sleep' . duration
    call assert_equal('aegim', &guioptions)
    set guioptions+=r
    exec 'sleep' . duration
    call assert_equal('aegimr', &guioptions)
    set guioptions+=L
    exec 'sleep' . duration
    call assert_equal('aegimrL', &guioptions)
    set guioptions+=t
    exec 'sleep' . duration
    call assert_equal('aegimrLt', &guioptions)
    set guioptions+=T
    exec 'sleep' . duration
    call assert_equal("aegimrLtT", &guioptions)

    wincmd o
    redraw!
  endif

  let &guioptions = guioptions_saved
endfunc

func Test_scrollbars()
  new
  " buffer with 200 lines
  call setline(1, repeat(['one', 'two'], 100))
  set guioptions+=rlb

  " scroll to move line 11 at top, moves the cursor there
  eval 10->test_scrollbar('left', 0)
  redraw
  call assert_equal(1, winline())
  call assert_equal(11, line('.'))

  " scroll to move line 1 at top, cursor stays in line 11
  call test_scrollbar('right', 0, 0)
  redraw
  call assert_equal(11, winline())
  call assert_equal(11, line('.'))

  set nowrap
  call setline(11, repeat('x', 150))
  redraw
  call assert_equal(1, wincol())
  set number
  redraw
  call assert_equal(5, wincol())
  set nonumber
  redraw
  call assert_equal(1, col('.'))

  " scroll to character 11, cursor is moved
  call test_scrollbar('hor', 10, 0)
  redraw
  call assert_equal(1, wincol())
  set number
  redraw
  call assert_equal(5, wincol())
  set nonumber
  redraw
  call assert_equal(11, col('.'))

  set guioptions&
  set wrap&
  bwipe!
endfunc

func Test_menu()
  CheckFeature quickfix

  " Check Help menu exists
  let help_menu = execute('menu Help')
  call assert_match('Overview', help_menu)

  " Check Help menu works
  emenu Help.Overview
  call assert_equal('help', &buftype)
  close

  " Check deleting menu doesn't cause trouble.
  aunmenu Help
  if exists(':tlmenu')
    tlunmenu Help
  endif
  call assert_fails('menu Help', 'E329:')
endfunc

func Test_set_guipty()
  let guipty_saved = &guipty

  " Default Value
  set guipty&
  call assert_equal(1, &guipty)

  set noguipty
  call assert_equal(0, &guipty)

  let &guipty = guipty_saved
endfunc

func Test_encoding_conversion()
  " GTK supports conversion between 'encoding' and "utf-8"
  CheckFeature gui_gtk
  let encoding_saved = &encoding
  set encoding=latin1

  " would be nice if we could take a screenshot
  intro
  " sets the window title
  edit SomeFile

  let &encoding = encoding_saved
endfunc

func Test_shell_command()
  new
  r !echo hello
  call assert_equal('hello', substitute(getline(2), '\W', '', 'g'))
  bwipe!
endfunc

func Test_syntax_colortest()
  runtime syntax/colortest.vim
  redraw!
  sleep 200m
  bwipe!
endfunc

func Test_set_term()
  " It's enough to check the current value since setting 'term' to anything
  " other than builtin_gui makes no sense at all.
  call assert_equal('builtin_gui', &term)
  call assert_fails('set term=xterm', 'E530:')
endfunc

func Test_windowid_variable()
  if g:x11_based_gui || has('win32')
    call assert_true(v:windowid > 0)
  else
    call assert_equal(0, v:windowid)
  endif
endfunc

" Test "vim -g" and also the GUIEnter autocommand.
func Test_gui_dash_g()
  let cmd = GetVimCommand('Xscriptgui')
  call writefile([""], "Xtestgui")
  let lines =<< trim END
	au GUIEnter * call writefile(["insertmode: " . &insertmode], "Xtestgui")
	au GUIEnter * qall
  END
  call writefile(lines, 'Xscriptgui')
  call system(cmd . ' -g')
  call WaitForAssert({-> assert_equal(['insertmode: 0'], readfile('Xtestgui'))})

  call delete('Xscriptgui')
  call delete('Xtestgui')
endfunc

" Test "vim -7" and also the GUIEnter autocommand.
func Test_gui_dash_y()
  let cmd = GetVimCommand('Xscriptgui')
  call writefile([""], "Xtestgui")
  let lines =<< trim END
	au GUIEnter * call writefile(["insertmode: " . &insertmode], "Xtestgui")
	au GUIEnter * qall
  END
  call writefile(lines, 'Xscriptgui')
  call system(cmd . ' -y')
  call WaitForAssert({-> assert_equal(['insertmode: 1'], readfile('Xtestgui'))})

  call delete('Xscriptgui')
  call delete('Xtestgui')
endfunc

" Test for "!" option in 'guioptions'. Use a terminal for running external
" commands
func Test_gui_run_cmd_in_terminal()
  CheckFeature terminal
  let save_guioptions = &guioptions
  set guioptions+=!
  if has('win32')
    let cmd = 'type'
  else
    " assume all the other systems have a cat command
    let cmd = 'cat'
  endif
  exe "silent !" . cmd . " test_gui.vim"
  " TODO: how to check that the command ran in a separate terminal?
  " Maybe check for $TERM (dumb vs xterm) in the spawned shell?
  let &guioptions = save_guioptions
endfunc

func Test_gui_recursive_mapping()
  nmap ' <C-W>
  nmap <C-W>a :let didit = 1<CR>
  call feedkeys("'a", 'xt')
  call assert_equal(1, didit)

  nunmap '
  nunmap <C-W>a
endfunc

" Test GUI mouse events
func Test_gui_mouse_event()
  set mousemodel=extend
  call test_override('no_query_mouse', 1)
  new
  call setline(1, ['one two three', 'four five six'])

  " place the cursor using left click in normal mode
  call cursor(1, 1)
  call test_gui_mouse_event(0, 2, 4, 0, 0)
  call test_gui_mouse_event(3, 2, 4, 0, 0)
  call feedkeys("\<Esc>", 'Lx!')
  call assert_equal([0, 2, 4, 0], getpos('.'))

  " select and yank a word
  let @" = ''
  call test_gui_mouse_event(0, 1, 9, 0, 0)
  call test_gui_mouse_event(0, 1, 9, 1, 0)
  call test_gui_mouse_event(3, 1, 9, 0, 0)
  call feedkeys("y", 'Lx!')
  call assert_equal('three', @")

  " create visual selection using right click
  let @" = ''
  call test_gui_mouse_event(0, 2, 6, 0, 0)
  call test_gui_mouse_event(3, 2, 6, 0, 0)
  call test_gui_mouse_event(2, 2, 13, 0, 0)
  call test_gui_mouse_event(3, 2, 13, 0, 0)
  call feedkeys("y", 'Lx!')
  call assert_equal('five six', @")

  " paste using middle mouse button
  let @* = 'abc '
  call feedkeys('""', 'Lx!')
  call test_gui_mouse_event(1, 1, 9, 0, 0)
  call test_gui_mouse_event(3, 1, 9, 0, 0)
  call feedkeys("\<Esc>", 'Lx!')
  call assert_equal(['one two abc three', 'four five six'], getline(1, '$'))

  " extend visual selection using right click in visual mode
  let @" = ''
  call cursor(1, 1)
  call feedkeys('v', 'Lx!')
  call test_gui_mouse_event(2, 1, 17, 0, 0)
  call test_gui_mouse_event(3, 1, 17, 0, 0)
  call feedkeys("y", 'Lx!')
  call assert_equal('one two abc three', @")

  " extend visual selection using mouse drag
  let @" = ''
  call cursor(1, 1)
  call test_gui_mouse_event(0, 2, 1, 0, 0)
  call test_gui_mouse_event(0x43, 2, 9, 0, 0)
  call test_gui_mouse_event(0x3, 2, 9, 0, 0)
  call feedkeys("y", 'Lx!')
  call assert_equal('four five', @")

  " select text by moving the mouse
  let @" = ''
  call cursor(1, 1)
  redraw!
  call test_gui_mouse_event(0, 1, 4, 0, 0)
  call test_gui_mouse_event(0x700, 1, 9, 0, 0)
  call test_gui_mouse_event(0x700, 1, 13, 0, 0)
  call test_gui_mouse_event(0x3, 1, 13, 0, 0)
  call feedkeys("y", 'Lx!')
  call assert_equal(' two abc t', @")

  " Using mouse in insert mode
  call cursor(1, 1)
  call feedkeys('i', 't')
  call test_gui_mouse_event(0, 2, 11, 0, 0)
  call test_gui_mouse_event(3, 2, 11, 0, 0)
  call feedkeys("po\<Esc>", 'Lx!')
  call assert_equal(['one two abc three', 'four five posix'], getline(1, '$'))

  %d _
  call setline(1, range(1, 100))
  " scroll up
  call test_gui_mouse_event(0x200, 2, 1, 0, 0)
  call test_gui_mouse_event(0x200, 2, 1, 0, 0)
  call test_gui_mouse_event(0x200, 2, 1, 0, 0)
  call feedkeys("H", 'Lx!')
  call assert_equal(10, line('.'))

  " scroll down
  call test_gui_mouse_event(0x100, 2, 1, 0, 0)
  call test_gui_mouse_event(0x100, 2, 1, 0, 0)
  call feedkeys("H", 'Lx!')
  call assert_equal(4, line('.'))

  %d _
  set nowrap
  call setline(1, range(10)->join('')->repeat(10))
  " scroll left
  call test_gui_mouse_event(0x500, 1, 5, 0, 0)
  call test_gui_mouse_event(0x500, 1, 10, 0, 0)
  call test_gui_mouse_event(0x500, 1, 15, 0, 0)
  call feedkeys('g0', 'Lx!')
  call assert_equal(19, col('.'))

  " scroll right
  call test_gui_mouse_event(0x600, 1, 15, 0, 0)
  call test_gui_mouse_event(0x600, 1, 10, 0, 0)
  call feedkeys('g0', 'Lx!')
  call assert_equal(7, col('.'))
  set wrap&

  %d _
  call setline(1, repeat([repeat('a', 60)], 10))

  " record various mouse events
  let mouseEventNames = [
        \ 'LeftMouse', 'LeftRelease', '2-LeftMouse', '3-LeftMouse',
        \ 'S-LeftMouse', 'A-LeftMouse', 'C-LeftMouse', 'MiddleMouse',
        \ 'MiddleRelease', '2-MiddleMouse', '3-MiddleMouse',
        \ 'S-MiddleMouse', 'A-MiddleMouse', 'C-MiddleMouse',
        \ 'RightMouse', 'RightRelease', '2-RightMouse',
        \ '3-RightMouse', 'S-RightMouse', 'A-RightMouse', 'C-RightMouse',
        \ 'X1Mouse', 'S-X1Mouse', 'A-X1Mouse', 'C-X1Mouse', 'X2Mouse',
        \ 'S-X2Mouse', 'A-X2Mouse', 'C-X2Mouse'
        \ ]
  let mouseEventCodes = map(copy(mouseEventNames), "'<' .. v:val .. '>'")
  let g:events = []
  for e in mouseEventCodes
    exe 'nnoremap ' .. e .. ' <Cmd>call add(g:events, "' ..
          \ substitute(e, '[<>]', '', 'g') .. '")<CR>'
  endfor

  " Test various mouse buttons (0 - Left, 1 - Middle, 2 - Right, 0x300 - X1,
  " 0x300- X2)
  for button in [0, 1, 2, 0x300, 0x400]
    " Single click
    call test_gui_mouse_event(button, 2, 5, 0, 0)
    call test_gui_mouse_event(3, 2, 5, 0, 0)

    " Double/Triple click is supported by only the Left/Middle/Right mouse
    " buttons
    if button <= 2
      " Double Click
      call test_gui_mouse_event(button, 2, 5, 0, 0)
      call test_gui_mouse_event(button, 2, 5, 1, 0)
      call test_gui_mouse_event(3, 2, 5, 0, 0)

      " Triple Click
      call test_gui_mouse_event(button, 2, 5, 0, 0)
      call test_gui_mouse_event(button, 2, 5, 1, 0)
      call test_gui_mouse_event(button, 2, 5, 1, 0)
      call test_gui_mouse_event(3, 2, 5, 0, 0)
    endif

    " Shift click
    call test_gui_mouse_event(button, 3, 7, 0, 4)
    call test_gui_mouse_event(3, 3, 7, 0, 4)

    " Alt click
    call test_gui_mouse_event(button, 3, 7, 0, 8)
    call test_gui_mouse_event(3, 3, 7, 0, 8)

    " Ctrl click
    call test_gui_mouse_event(button, 3, 7, 0, 16)
    call test_gui_mouse_event(3, 3, 7, 0, 16)

    call feedkeys("\<Esc>", 'Lx!')
  endfor

  call assert_equal(['LeftMouse', 'LeftRelease', 'LeftMouse', '2-LeftMouse',
        \ 'LeftMouse', '2-LeftMouse', '3-LeftMouse', 'S-LeftMouse',
        \ 'A-LeftMouse', 'C-LeftMouse', 'MiddleMouse', 'MiddleRelease',
        \ 'MiddleMouse', '2-MiddleMouse', 'MiddleMouse', '2-MiddleMouse',
        \ '3-MiddleMouse', 'S-MiddleMouse', 'A-MiddleMouse', 'C-MiddleMouse',
        \ 'RightMouse', 'RightRelease', 'RightMouse', '2-RightMouse',
        \ 'RightMouse', '2-RightMouse', '3-RightMouse', 'S-RightMouse',
        \ 'A-RightMouse', 'C-RightMouse', 'X1Mouse', 'S-X1Mouse', 'A-X1Mouse',
        \ 'C-X1Mouse', 'X2Mouse', 'S-X2Mouse', 'A-X2Mouse', 'C-X2Mouse'],
        \ g:events)

  for e in mouseEventCodes
    exe 'nunmap ' .. e
  endfor

  " modeless selection
  set mouse=
  let save_guioptions = &guioptions
  set guioptions+=A
  %d _
  call setline(1, ['one two three', 'four five sixteen'])
  call cursor(1, 1)
  redraw!
  " Double click should select the word and copy it to clipboard
  let @* = ''
  call test_gui_mouse_event(0, 2, 11, 0, 0)
  call test_gui_mouse_event(0, 2, 11, 1, 0)
  call test_gui_mouse_event(3, 2, 11, 0, 0)
  call feedkeys("\<Esc>", 'Lx!')
  call assert_equal([0, 1, 1, 0], getpos('.'))
  call assert_equal('sixteen', @*)
  " Right click should extend the selection from cursor
  call cursor(1, 6)
  redraw!
  let @* = ''
  call test_gui_mouse_event(2, 1, 11, 0, 0)
  call test_gui_mouse_event(3, 1, 11, 0, 0)
  call feedkeys("\<Esc>", 'Lx!')
  call assert_equal([0, 1, 6, 0], getpos('.'))
  call assert_equal('wo thr', @*)
  " Middle click should paste the clipboard contents
  call cursor(2, 1)
  redraw!
  call test_gui_mouse_event(1, 1, 11, 0, 0)
  call test_gui_mouse_event(3, 1, 11, 0, 0)
  call feedkeys("\<Esc>", 'Lx!')
  call assert_equal([0, 2, 7, 0], getpos('.'))
  call assert_equal('wo thrfour five sixteen', getline(2))
  set mouse&
  let &guioptions = save_guioptions

  " Test invalid parameters for test_gui_mouse_event()
  call assert_fails('call test_gui_mouse_event("", 1, 2, 3, 4)', 'E1210:')
  call assert_fails('call test_gui_mouse_event(0, "", 2, 3, 4)', 'E1210:')
  call assert_fails('call test_gui_mouse_event(0, 1, "", 3, 4)', 'E1210:')
  call assert_fails('call test_gui_mouse_event(0, 1, 2, "", 4)', 'E1210:')
  call assert_fails('call test_gui_mouse_event(0, 1, 2, 3, "")', 'E1210:')

  bw!
  call test_override('no_query_mouse', 0)
  set mousemodel&
endfunc

" Test for 'guitablabel' and 'guitabtooltip' options
func TestGuiTabLabel()
  call add(g:TabLabels, v:lnum + 100)
  let bufnrlist = tabpagebuflist(v:lnum)
  return bufname(bufnrlist[tabpagewinnr(v:lnum) - 1])
endfunc

func TestGuiTabToolTip()
  call add(g:TabToolTips, v:lnum + 200)
  let bufnrlist = tabpagebuflist(v:lnum)
  return bufname(bufnrlist[tabpagewinnr(v:lnum) - 1])
endfunc

func Test_gui_tablabel_tooltip()
  CheckNotFeature gui_athena

  %bw!
  " Removing the tabline at the end of this test, reduces the window height by
  " one. Save and restore it after the test.
  let save_lines = &lines
  edit one
  set modified
  tabnew two
  set modified
  tabnew three
  set modified
  let g:TabLabels = []
  set guitablabel=%{TestGuiTabLabel()}
  call test_override('starting', 1)
  redrawtabline
  call test_override('starting', 0)
  call assert_true(index(g:TabLabels, 101) != -1)
  call assert_true(index(g:TabLabels, 102) != -1)
  call assert_true(index(g:TabLabels, 103) != -1)
  set guitablabel&
  unlet g:TabLabels

  if has('gui_gtk')
    " Only on GTK+, the tooltip function is called even if the mouse is not
    " on the tabline. on Win32 and Motif, the tooltip function is called only
    " when the mouse pointer is over the tabline.
    let g:TabToolTips = []
    set guitabtooltip=%{TestGuiTabToolTip()}
    call test_override('starting', 1)
    redrawtabline
    call test_override('starting', 0)
    call assert_true(index(g:TabToolTips, 201) != -1)
    call assert_true(index(g:TabToolTips, 202) != -1)
    call assert_true(index(g:TabToolTips, 203) != -1)
    set guitabtooltip&
    unlet g:TabToolTips
  endif
  %bw!
  let &lines = save_lines
endfunc

" Test for dropping files into a window in GUI
func DropFilesInCmdLine()
  CheckFeature drop_file

  call feedkeys(":\"", 'L')
  call test_gui_drop_files(['a.c', 'b.c'], &lines, 1, 0)
  call feedkeys("\<CR>", 'L')
endfunc

func Test_gui_drop_files()
  CheckFeature drop_file

  call assert_fails('call test_gui_drop_files(1, 1, 1, 0)', 'E1211:')
  call assert_fails('call test_gui_drop_files(["x"], "", 1, 0)', 'E1210:')
  call assert_fails('call test_gui_drop_files(["x"], 1, "", 0)', 'E1210:')
  call assert_fails('call test_gui_drop_files(["x"], 1, 1, "")', 'E1210:')

  %bw!
  %argdelete
  call test_gui_drop_files([], 1, 1, 0)
  call assert_equal([], argv())
  call test_gui_drop_files([1, 2], 1, 1, 0)
  call assert_equal([], argv())

  call test_gui_drop_files(['a.c', 'b.c'], 1, 1, 0)
  call assert_equal(['a.c', 'b.c'], argv())
  %bw!
  %argdelete
  call test_gui_drop_files([], 1, 1, 0)
  call assert_equal([], argv())
  %bw!
  " if the buffer in the window is modified, then the file should be opened in
  " a new window
  set modified
  call test_gui_drop_files(['x.c', 'y.c'], 1, 1, 0)
  call assert_equal(['x.c', 'y.c'], argv())
  call assert_equal(2, winnr('$'))
  call assert_equal('x.c', bufname(winbufnr(1)))
  %bw!
  %argdelete
  " if Ctrl is pressed, then the file should be opened in a new window
  call test_gui_drop_files(['s.py', 't.py'], 1, 1, 0x10)
  call assert_equal(['s.py', 't.py'], argv())
  call assert_equal(2, winnr('$'))
  call assert_equal('s.py', bufname(winbufnr(1)))
  %bw!
  %argdelete
  " drop the files in a non-current window
  belowright new
  call test_gui_drop_files(['a.py', 'b.py'], 1, 1, 0)
  call assert_equal(['a.py', 'b.py'], argv())
  call assert_equal(2, winnr('$'))
  call assert_equal(1, winnr())
  call assert_equal('a.py', bufname(winbufnr(1)))
  %bw!
  %argdelete
  " pressing shift when dropping files should change directory
  let save_cwd = getcwd()
  call mkdir('Xdir1')
  call writefile([], 'Xdir1/Xfile1')
  call writefile([], 'Xdir1/Xfile2')
  call test_gui_drop_files(['Xdir1/Xfile1', 'Xdir1/Xfile2'], 1, 1, 0x4)
  call assert_equal('Xdir1', fnamemodify(getcwd(), ':t'))
  call assert_equal('Xfile1', @%)
  call chdir(save_cwd)
  " pressing shift when dropping directory and files should change directory
  call test_gui_drop_files(['Xdir1', 'Xdir1/Xfile2'], 1, 1, 0x4)
  call assert_equal('Xdir1', fnamemodify(getcwd(), ':t'))
  call assert_equal('Xdir1', fnamemodify(@%, ':t'))
  call chdir(save_cwd)
  %bw!
  %argdelete
  " dropping a directory should edit it
  call test_gui_drop_files(['Xdir1'], 1, 1, 0)
  call assert_equal('Xdir1', @%)
  %bw!
  %argdelete
  " dropping only a directory name with Shift should ignore it
  call test_gui_drop_files(['Xdir1'], 1, 1, 0x4)
  call assert_equal('', @%)
  %bw!
  %argdelete
  call delete('Xdir1', 'rf')
  " drop files in the command line. The GUI drop files adds the file names to
  " the low level input buffer. So need to use a cmdline map and feedkeys()
  " with 'Lx!' to process it in this function itself.
  cnoremap <expr> <buffer> <F4> DropFilesInCmdLine()
  call feedkeys(":\"\<F4>\<CR>", 'xt')
  call feedkeys('k', 'Lx!')
  call assert_equal('"a.c b.c', @:)
  cunmap <buffer> <F4>
endfunc

" Test for generating a GUI tabline event to select a tab page
func Test_gui_tabline_event()
  %bw!
  edit Xfile1
  tabedit Xfile2
  tabedit Xfile3

  tabfirst
  call assert_equal(v:true, test_gui_tabline_event(2))
  call feedkeys("y", "Lx!")
  call assert_equal(2, tabpagenr())
  call assert_equal(v:true, test_gui_tabline_event(3))
  call feedkeys("y", "Lx!")
  call assert_equal(3, tabpagenr())
  call assert_equal(v:false, test_gui_tabline_event(3))

  " From the cmdline window, tabline event should not be handled
  call feedkeys("q::let t = test_gui_tabline_event(2)\<CR>:q\<CR>", 'x!')
  call assert_equal(v:false, t)

  %bw!
endfunc

" Test for generating a GUI tabline menu event to execute an action
func Test_gui_tabmenu_event()
  %bw!

  " Try to close the last tab page
  call test_gui_tabmenu_event(1, 1)
  call feedkeys("y", "Lx!")

  edit Xfile1
  tabedit Xfile2
  call test_gui_tabmenu_event(1, 1)
  call feedkeys("y", "Lx!")
  call assert_equal(1, tabpagenr('$'))
  call assert_equal('Xfile2', bufname())

  call test_gui_tabmenu_event(1, 2)
  call feedkeys("y", "Lx!")
  call assert_equal(2, tabpagenr('$'))

  " If tabnr is 0, then the current tabpage should be used.
  call test_gui_tabmenu_event(0, 2)
  call feedkeys("y", "Lx!")
  call assert_equal(3, tabpagenr('$'))
  call test_gui_tabmenu_event(0, 1)
  call feedkeys("y", "Lx!")
  call assert_equal(2, tabpagenr('$'))

  %bw!
endfunc

" vim: shiftwidth=2 sts=2 expandtab
