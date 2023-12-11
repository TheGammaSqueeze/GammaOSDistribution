" Test various aspects of the Vim9 script language.

source check.vim
source term_util.vim
source vim9.vim
source screendump.vim
source shared.vim

def Test_vim9script_feature()
  # example from the help, here the feature is always present
  var lines =<< trim END
      " old style comment
      if !has('vim9script')
        " legacy commands would go here
        finish
      endif
      vim9script
      # Vim9 script commands go here
      g:didit = true
  END
  CheckScriptSuccess(lines)
  assert_equal(true, g:didit)
  unlet g:didit
enddef

def Test_range_only()
  new
  setline(1, ['blah', 'Blah'])
  :/Blah/
  assert_equal(2, getcurpos()[1])
  bwipe!

  # without range commands use current line
  new
  setline(1, ['one', 'two', 'three'])
  :2
  print
  assert_equal('two', Screenline(&lines))
  :3
  list
  assert_equal('three$', Screenline(&lines))

  # missing command does not print the line
  var lines =<< trim END
    vim9script
    :1|
    assert_equal('three$', Screenline(&lines))
    :|
    assert_equal('three$', Screenline(&lines))
  END
  CheckScriptSuccess(lines)

  bwipe!

  # won't generate anything
  if false
    :123
  endif
enddef

let g:alist = [7]
let g:astring = 'text'
let g:anumber = 123

def Test_delfunction()
  # Check function is defined in script namespace
  CheckScriptSuccess([
      'vim9script',
      'func CheckMe()',
      '  return 123',
      'endfunc',
      'assert_equal(123, s:CheckMe())',
      ])

  # Check function in script namespace cannot be deleted
  CheckScriptFailure([
      'vim9script',
      'func DeleteMe1()',
      'endfunc',
      'delfunction DeleteMe1',
      ], 'E1084:')
  CheckScriptFailure([
      'vim9script',
      'func DeleteMe2()',
      'endfunc',
      'def DoThat()',
      '  delfunction DeleteMe2',
      'enddef',
      'DoThat()',
      ], 'E1084:')
  CheckScriptFailure([
      'vim9script',
      'def DeleteMe3()',
      'enddef',
      'delfunction DeleteMe3',
      ], 'E1084:')
  CheckScriptFailure([
      'vim9script',
      'def DeleteMe4()',
      'enddef',
      'def DoThat()',
      '  delfunction DeleteMe4',
      'enddef',
      'DoThat()',
      ], 'E1084:')

  # Check that global :def function can be replaced and deleted
  var lines =<< trim END
      vim9script
      def g:Global(): string
        return "yes"
      enddef
      assert_equal("yes", g:Global())
      def! g:Global(): string
        return "no"
      enddef
      assert_equal("no", g:Global())
      delfunc g:Global
      assert_false(exists('*g:Global'))
  END
  CheckScriptSuccess(lines)

  # Check that global function can be replaced by a :def function and deleted
  lines =<< trim END
      vim9script
      func g:Global()
        return "yes"
      endfunc
      assert_equal("yes", g:Global())
      def! g:Global(): string
        return "no"
      enddef
      assert_equal("no", g:Global())
      delfunc g:Global
      assert_false(exists('*g:Global'))
  END
  CheckScriptSuccess(lines)

  # Check that global :def function can be replaced by a function and deleted
  lines =<< trim END
      vim9script
      def g:Global(): string
        return "yes"
      enddef
      assert_equal("yes", g:Global())
      func! g:Global()
        return "no"
      endfunc
      assert_equal("no", g:Global())
      delfunc g:Global
      assert_false(exists('*g:Global'))
  END
  CheckScriptSuccess(lines)
enddef

def Test_wrong_type()
  CheckDefFailure(['var name: list<nothing>'], 'E1010:')
  CheckDefFailure(['var name: list<list<nothing>>'], 'E1010:')
  CheckDefFailure(['var name: dict<nothing>'], 'E1010:')
  CheckDefFailure(['var name: dict<dict<nothing>>'], 'E1010:')

  CheckDefFailure(['var name: dict<number'], 'E1009:')
  CheckDefFailure(['var name: dict<list<number>'], 'E1009:')

  CheckDefFailure(['var name: ally'], 'E1010:')
  CheckDefFailure(['var name: bram'], 'E1010:')
  CheckDefFailure(['var name: cathy'], 'E1010:')
  CheckDefFailure(['var name: dom'], 'E1010:')
  CheckDefFailure(['var name: freddy'], 'E1010:')
  CheckDefFailure(['var name: john'], 'E1010:')
  CheckDefFailure(['var name: larry'], 'E1010:')
  CheckDefFailure(['var name: ned'], 'E1010:')
  CheckDefFailure(['var name: pam'], 'E1010:')
  CheckDefFailure(['var name: sam'], 'E1010:')
  CheckDefFailure(['var name: vim'], 'E1010:')

  CheckDefFailure(['var Ref: number', 'Ref()'], 'E1085:')
  CheckDefFailure(['var Ref: string', 'var res = Ref()'], 'E1085:')
enddef

def Test_script_wrong_type()
  var lines =<< trim END
      vim9script
      var s:dict: dict<string>
      s:dict['a'] = ['x']
  END
  CheckScriptFailure(lines, 'E1012: Type mismatch; expected string but got list<string>', 3)
enddef

def Test_const()
  CheckDefFailure(['final name = 234', 'name = 99'], 'E1018:')
  CheckDefFailure(['final one = 234', 'var one = 99'], 'E1017:')
  CheckDefFailure(['final list = [1, 2]', 'var list = [3, 4]'], 'E1017:')
  CheckDefFailure(['final two'], 'E1125:')
  CheckDefFailure(['final &option'], 'E996:')

  var lines =<< trim END
    final list = [1, 2, 3]
    list[0] = 4
    list->assert_equal([4, 2, 3])
    const other = [5, 6, 7]
    other->assert_equal([5, 6, 7])

    var varlist = [7, 8]
    const constlist = [1, varlist, 3]
    varlist[0] = 77
    constlist[1][1] = 88
    var cl = constlist[1]
    cl[1] = 88
    constlist->assert_equal([1, [77, 88], 3])

    var vardict = {five: 5, six: 6}
    const constdict = {one: 1, two: vardict, three: 3}
    vardict['five'] = 55
    constdict['two']['six'] = 66
    var cd = constdict['two']
    cd['six'] = 66
    constdict->assert_equal({one: 1, two: {five: 55, six: 66}, three: 3})
  END
  CheckDefAndScriptSuccess(lines)
enddef

def Test_const_bang()
  var lines =<< trim END
      const var = 234
      var = 99
  END
  CheckDefExecFailure(lines, 'E1018:', 2)
  CheckScriptFailure(['vim9script'] + lines, 'E46:', 3)

  lines =<< trim END
      const ll = [2, 3, 4]
      ll[0] = 99
  END
  CheckDefExecFailure(lines, 'E1119:', 2)
  CheckScriptFailure(['vim9script'] + lines, 'E741:', 3)

  lines =<< trim END
      const ll = [2, 3, 4]
      ll[3] = 99
  END
  CheckDefExecFailure(lines, 'E1118:', 2)
  CheckScriptFailure(['vim9script'] + lines, 'E684:', 3)

  lines =<< trim END
      const dd = {one: 1, two: 2}
      dd["one"] = 99
  END
  CheckDefExecFailure(lines, 'E1121:', 2)
  CheckScriptFailure(['vim9script'] + lines, 'E741:', 3)

  lines =<< trim END
      const dd = {one: 1, two: 2}
      dd["three"] = 99
  END
  CheckDefExecFailure(lines, 'E1120:')
  CheckScriptFailure(['vim9script'] + lines, 'E741:', 3)
enddef

def Test_range_no_colon()
  CheckDefFailure(['%s/a/b/'], 'E1050:')
  CheckDefFailure(['+ s/a/b/'], 'E1050:')
  CheckDefFailure(['- s/a/b/'], 'E1050:')
  CheckDefFailure(['. s/a/b/'], 'E1050:')
enddef


def Test_block()
  var outer = 1
  {
    var inner = 2
    assert_equal(1, outer)
    assert_equal(2, inner)
  }
  assert_equal(1, outer)

  {|echo 'yes'|}
enddef

def Test_block_failure()
  CheckDefFailure(['{', 'var inner = 1', '}', 'echo inner'], 'E1001:')
  CheckDefFailure(['}'], 'E1025:')
  CheckDefFailure(['{', 'echo 1'], 'E1026:')
enddef

def Test_block_local_vars()
  var lines =<< trim END
      vim9script
      v:testing = 1
      if true
        var text = ['hello']
        def SayHello(): list<string>
          return text
        enddef
        def SetText(v: string)
          text = [v]
        enddef
      endif

      if true
        var text = ['again']
        def SayAgain(): list<string>
          return text
        enddef
      endif

      # test that the "text" variables are not cleaned up
      test_garbagecollect_now()

      defcompile

      assert_equal(['hello'], SayHello())
      assert_equal(['again'], SayAgain())

      SetText('foobar')
      assert_equal(['foobar'], SayHello())

      call writefile(['ok'], 'Xdidit')
      qall!
  END

  # need to execute this with a separate Vim instance to avoid the current
  # context gets garbage collected.
  writefile(lines, 'Xscript')
  RunVim([], [], '-S Xscript')
  assert_equal(['ok'], readfile('Xdidit'))

  delete('Xscript')
  delete('Xdidit')
enddef

def Test_block_local_vars_with_func()
  var lines =<< trim END
      vim9script
      if true
        var foo = 'foo'
        if true
          var bar = 'bar'
          def Func(): list<string>
            return [foo, bar]
          enddef
        endif
      endif
      # function is compiled here, after blocks have finished, can still access
      # "foo" and "bar"
      assert_equal(['foo', 'bar'], Func())
  END
  CheckScriptSuccess(lines)
enddef

" legacy func for command that's defined later
func InvokeSomeCommand()
  SomeCommand
endfunc

def Test_autocommand_block()
  com SomeCommand {
      g:someVar = 'some'
    }
  InvokeSomeCommand()
  assert_equal('some', g:someVar)

  delcommand SomeCommand
  unlet g:someVar
enddef

def Test_command_block()
  au BufNew *.xml {
      g:otherVar = 'other'
    }
  split other.xml
  assert_equal('other', g:otherVar)

  bwipe!
  au! BufNew *.xml
  unlet g:otherVar
enddef

func g:NoSuchFunc()
  echo 'none'
endfunc

def Test_try_catch_throw()
  var l = []
  try # comment
    add(l, '1')
    throw 'wrong'
    add(l, '2')
  catch # comment
    add(l, v:exception)
  finally # comment
    add(l, '3')
  endtry # comment
  assert_equal(['1', 'wrong', '3'], l)

  l = []
  try
    try
      add(l, '1')
      throw 'wrong'
      add(l, '2')
    catch /right/
      add(l, v:exception)
    endtry
  catch /wrong/
    add(l, 'caught')
  fina
    add(l, 'finally')
  endtry
  assert_equal(['1', 'caught', 'finally'], l)

  var n: number
  try
    n = l[3]
  catch /E684:/
    n = 99
  endtry
  assert_equal(99, n)

  var done = 'no'
  if 0
    try | catch | endtry
  else
    done = 'yes'
  endif
  assert_equal('yes', done)

  done = 'no'
  if 1
    done = 'yes'
  else
    try | catch | endtry
    done = 'never'
  endif
  assert_equal('yes', done)

  if 1
  else
    try | catch /pat/ | endtry
    try | catch /pat/ 
    endtry
    try 
    catch /pat/ | endtry
    try 
    catch /pat/ 
    endtry
  endif

  try
    # string slice returns a string, not a number
    n = g:astring[3]
  catch /E1012:/
    n = 77
  endtry
  assert_equal(77, n)

  try
    n = l[g:astring]
  catch /E1012:/
    n = 88
  endtry
  assert_equal(88, n)

  try
    n = s:does_not_exist
  catch /E121:/
    n = 111
  endtry
  assert_equal(111, n)

  try
    n = g:does_not_exist
  catch /E121:/
    n = 121
  endtry
  assert_equal(121, n)

  var d = {one: 1}
  try
    n = d[g:astring]
  catch /E716:/
    n = 222
  endtry
  assert_equal(222, n)

  try
    n = -g:astring
  catch /E1012:/
    n = 233
  endtry
  assert_equal(233, n)

  try
    n = +g:astring
  catch /E1012:/
    n = 244
  endtry
  assert_equal(244, n)

  try
    n = +g:alist
  catch /E1012:/
    n = 255
  endtry
  assert_equal(255, n)

  var nd: dict<any>
  try
    nd = {[g:alist]: 1}
  catch /E1105:/
    n = 266
  endtry
  assert_equal(266, n)

  l = [1, 2, 3] 
  try
    [n] = l
  catch /E1093:/
    n = 277
  endtry
  assert_equal(277, n)

  try
    &ts = g:astring
  catch /E1012:/
    n = 288
  endtry
  assert_equal(288, n)

  try
    &backspace = 'asdf'
  catch /E474:/
    n = 299
  endtry
  assert_equal(299, n)

  l = [1]
  try
    l[3] = 3
  catch /E684:/
    n = 300
  endtry
  assert_equal(300, n)

  try
    unlet g:does_not_exist
  catch /E108:/
    n = 322
  endtry
  assert_equal(322, n)

  try
    d = {text: 1, [g:astring]: 2}
  catch /E721:/
    n = 333
  endtry
  assert_equal(333, n)

  try
    l = DeletedFunc()
  catch /E933:/
    n = 344
  endtry
  assert_equal(344, n)

  try
    echo range(1, 2, 0)
  catch /E726:/
    n = 355
  endtry
  assert_equal(355, n)

  var P = function('g:NoSuchFunc')
  delfunc g:NoSuchFunc
  try
    echo P()
  catch /E117:/
    n = 366
  endtry
  assert_equal(366, n)

  try
    echo g:NoSuchFunc()
  catch /E117:/
    n = 377
  endtry
  assert_equal(377, n)

  try
    echo g:alist + 4
  catch /E745:/
    n = 388
  endtry
  assert_equal(388, n)

  try
    echo 4 + g:alist
  catch /E745:/
    n = 399
  endtry
  assert_equal(399, n)

  try
    echo g:alist.member
  catch /E715:/
    n = 400
  endtry
  assert_equal(400, n)

  try
    echo d.member
  catch /E716:/
    n = 411
  endtry
  assert_equal(411, n)

  var counter = 0
  for i in range(4)
    try
      eval [][0]
    catch
    endtry
    counter += 1
  endfor
  assert_equal(4, counter)

  # no requirement for spaces before |
  try|echo 0|catch|endtry

  # return in try with finally
  def ReturnInTry(): number
    var ret = 4
    try
      return ret
    catch /this/
      return -1
    catch /that/
      return -1
    finally
      # changing ret has no effect
      ret = 7
    endtry
    return -2
  enddef
  assert_equal(4, ReturnInTry())

  # return in catch with finally
  def ReturnInCatch(): number
    var ret = 5
    try
      throw 'getout'
      return -1
    catch /getout/
      # ret is evaluated here
      return ret
    finally
      # changing ret later has no effect
      ret = -3
    endtry
    return -2
  enddef
  assert_equal(5, ReturnInCatch())

  # return in finally after empty catch
  def ReturnInFinally(): number
    try
    finally
      return 6
    endtry
  enddef
  assert_equal(6, ReturnInFinally())

  var lines =<< trim END
      vim9script
      try
        acos('0.5')
          ->setline(1)
      catch
        g:caught = v:exception
      endtry
  END
  CheckScriptSuccess(lines)
  assert_match('E1219: Float or Number required for argument 1', g:caught)
  unlet g:caught

  # missing catch and/or finally
  lines =<< trim END
      vim9script
      try
        echo 'something'
      endtry
  END
  CheckScriptFailure(lines, 'E1032:')

  # skipping try-finally-endtry when try-finally-endtry is used in another block
  lines =<< trim END
      if v:true
        try
        finally
        endtry
      else
        try
        finally
        endtry
      endif
  END
  CheckDefAndScriptSuccess(lines)
enddef

def Test_try_ends_in_return()
  var lines =<< trim END
      vim9script
      def Foo(): string
        try
          return 'foo'
        catch
          return 'caught'
        endtry
      enddef
      assert_equal('foo', Foo())
  END
  CheckScriptSuccess(lines)

  lines =<< trim END
      vim9script
      def Foo(): string
        try
          return 'foo'
        catch
          return 'caught'
        endtry
        echo 'notreached'
      enddef
      assert_equal('foo', Foo())
  END
  CheckScriptFailure(lines, 'E1095:')

  lines =<< trim END
      vim9script
      def Foo(): string
        try
          return 'foo'
        catch /x/
          return 'caught'
        endtry
      enddef
      assert_equal('foo', Foo())
  END
  CheckScriptFailure(lines, 'E1027:')

  lines =<< trim END
      vim9script
      def Foo(): string
        try
          echo 'foo'
        catch
          echo 'caught'
        finally
          return 'done'
        endtry
      enddef
      assert_equal('done', Foo())
  END
  CheckScriptSuccess(lines)

enddef

def Test_try_in_catch()
  var lines =<< trim END
      vim9script
      var seq = []
      def DoIt()
        try
          seq->add('throw 1')
          eval [][0]
          seq->add('notreached')
        catch
          seq->add('catch')
          try
            seq->add('throw 2')
            eval [][0]
            seq->add('notreached')
          catch /nothing/
            seq->add('notreached')
          endtry
          seq->add('done')
        endtry
      enddef
      DoIt()
      assert_equal(['throw 1', 'catch', 'throw 2', 'done'], seq)
  END
enddef

def Test_error_in_catch()
  var lines =<< trim END
      try
        eval [][0]
      catch /E684:/
        eval [][0]
      endtry
  END
  CheckDefExecFailure(lines, 'E684:', 4)
enddef

" :while at the very start of a function that :continue jumps to
def TryContinueFunc()
 while g:Count < 2
   g:sequence ..= 't'
    try
      echoerr 'Test'
    catch
      g:Count += 1
      g:sequence ..= 'c'
      continue
    endtry
    g:sequence ..= 'e'
    g:Count += 1
  endwhile
enddef

def Test_continue_in_try_in_while()
  g:Count = 0
  g:sequence = ''
  TryContinueFunc()
  assert_equal('tctc', g:sequence)
  unlet g:Count
  unlet g:sequence
enddef

def Test_nocatch_return_in_try()
  # return in try block returns normally
  def ReturnInTry(): string
    try
      return '"some message"'
    catch
    endtry
    return 'not reached'
  enddef
  exe 'echoerr ' .. ReturnInTry()
enddef

def Test_cnext_works_in_catch()
  var lines =<< trim END
      vim9script
      au BufEnter * eval 1 + 2
      writefile(['text'], 'Xfile1')
      writefile(['text'], 'Xfile2')
      var items = [
          {lnum: 1, filename: 'Xfile1', valid: true},
          {lnum: 1, filename: 'Xfile2', valid: true}
        ]
      setqflist([], ' ', {items: items})
      cwindow

      def CnextOrCfirst()
        # if cnext fails, cfirst is used
        try
          cnext
        catch
          cfirst
        endtry
      enddef

      CnextOrCfirst()
      CnextOrCfirst()
      writefile([getqflist({idx: 0}).idx], 'Xresult')
      qall
  END
  writefile(lines, 'XCatchCnext')
  RunVim([], [], '--clean -S XCatchCnext')
  assert_equal(['1'], readfile('Xresult'))

  delete('Xfile1')
  delete('Xfile2')
  delete('XCatchCnext')
  delete('Xresult')
enddef

def Test_throw_skipped()
  if 0
    throw dontgethere
  endif
enddef

def Test_nocatch_throw_silenced()
  var lines =<< trim END
    vim9script
    def Func()
      throw 'error'
    enddef
    silent! Func()
  END
  writefile(lines, 'XthrowSilenced')
  source XthrowSilenced
  delete('XthrowSilenced')
enddef

def DeletedFunc(): list<any>
  return ['delete me']
enddef
defcompile
delfunc DeletedFunc

def ThrowFromDef()
  throw "getout" # comment
enddef

func CatchInFunc()
  try
    call ThrowFromDef()
  catch
    let g:thrown_func = v:exception
  endtry
endfunc

def CatchInDef()
  try
    ThrowFromDef()
  catch
    g:thrown_def = v:exception
  endtry
enddef

def ReturnFinally(): string
  try
    return 'intry'
  finall
    g:in_finally = 'finally'
  endtry
  return 'end'
enddef

def Test_try_catch_nested()
  CatchInFunc()
  assert_equal('getout', g:thrown_func)

  CatchInDef()
  assert_equal('getout', g:thrown_def)

  assert_equal('intry', ReturnFinally())
  assert_equal('finally', g:in_finally)

  var l = []
  try
    l->add('1')
    throw 'bad'
    l->add('x')
  catch /bad/
    l->add('2')
    try
      l->add('3')
      throw 'one'
      l->add('x')
    catch /one/
      l->add('4')
      try
        l->add('5')
        throw 'more'
        l->add('x')
      catch /more/
        l->add('6')
      endtry
    endtry
  endtry
  assert_equal(['1', '2', '3', '4', '5', '6'], l)

  l = []
  try
    try
      l->add('1')
      throw 'foo'
      l->add('x')
    catch
      l->add('2')
      throw 'bar'
      l->add('x')
    finally
      l->add('3')
    endtry
    l->add('x')
  catch /bar/
    l->add('4')
  endtry
  assert_equal(['1', '2', '3', '4'], l)
enddef

def TryOne(): number
  try
    return 0
  catch
  endtry
  return 0
enddef

def TryTwo(n: number): string
  try
    var x = {}
  catch
  endtry
  return 'text'
enddef

def Test_try_catch_twice()
  assert_equal('text', TryOne()->TryTwo())
enddef

def Test_try_catch_match()
  var seq = 'a'
  try
    throw 'something'
  catch /nothing/
    seq ..= 'x'
  catch /some/
    seq ..= 'b'
  catch /asdf/
    seq ..= 'x'
  catch ?a\?sdf?
    seq ..= 'y'
  finally
    seq ..= 'c'
  endtry
  assert_equal('abc', seq)
enddef

def Test_try_catch_fails()
  CheckDefFailure(['catch'], 'E603:')
  CheckDefFailure(['try', 'echo 0', 'catch', 'catch'], 'E1033:')
  CheckDefFailure(['try', 'echo 0', 'catch /pat'], 'E1067:')
  CheckDefFailure(['finally'], 'E606:')
  CheckDefFailure(['try', 'echo 0', 'finally', 'echo 1', 'finally'], 'E607:')
  CheckDefFailure(['endtry'], 'E602:')
  CheckDefFailure(['while 1', 'endtry'], 'E170:')
  CheckDefFailure(['for i in range(5)', 'endtry'], 'E170:')
  CheckDefFailure(['if 1', 'endtry'], 'E171:')
  CheckDefFailure(['try', 'echo 1', 'endtry'], 'E1032:')

  CheckDefFailure(['throw'], 'E1143:')
  CheckDefFailure(['throw xxx'], 'E1001:')
enddef

def Try_catch_skipped()
  var l = []
  try
  finally
  endtry

  if 1
  else
    try
    endtry
  endif
enddef

" The skipped try/endtry was updating the wrong instruction.
def Test_try_catch_skipped()
  var instr = execute('disassemble Try_catch_skipped')
  assert_match("NEWLIST size 0\n", instr)
enddef



def Test_throw_vimscript()
  # only checks line continuation
  var lines =<< trim END
      vim9script
      try
        throw 'one'
              .. 'two'
      catch
        assert_equal('onetwo', v:exception)
      endtry
  END
  CheckScriptSuccess(lines)

  lines =<< trim END
    vim9script
    @r = ''
    def Func()
      throw @r
    enddef
    var result = ''
    try
      Func()
    catch /E1129:/
      result = 'caught'
    endtry
    assert_equal('caught', result)
  END
  CheckScriptSuccess(lines)
enddef

def Test_error_in_nested_function()
  # an error in a nested :function aborts executing in the calling :def function
  var lines =<< trim END
      vim9script
      def Func()
        Error()
        g:test_var = 1
      enddef
      func Error() abort
        eval [][0]
      endfunc
      Func()
  END
  g:test_var = 0
  CheckScriptFailure(lines, 'E684:')
  assert_equal(0, g:test_var)
enddef

def Test_abort_after_error()
  var lines =<< trim END
      vim9script
      while true
        echo notfound
      endwhile
      g:gotthere = true
  END
  g:gotthere = false
  CheckScriptFailure(lines, 'E121:')
  assert_false(g:gotthere)
  unlet g:gotthere
enddef

def Test_cexpr_vimscript()
  # only checks line continuation
  set errorformat=File\ %f\ line\ %l
  var lines =<< trim END
      vim9script
      cexpr 'File'
                .. ' someFile' ..
                   ' line 19'
      assert_equal(19, getqflist()[0].lnum)
  END
  CheckScriptSuccess(lines)
  set errorformat&
enddef

def Test_statusline_syntax()
  # legacy syntax is used for 'statusline'
  var lines =<< trim END
      vim9script
      func g:Status()
        return '%{"x" is# "x"}'
      endfunc
      set laststatus=2 statusline=%!Status()
      redrawstatus
      set laststatus statusline= 
  END
  CheckScriptSuccess(lines)
enddef

def Test_list_vimscript()
  # checks line continuation and comments
  var lines =<< trim END
      vim9script
      var mylist = [
            'one',
            # comment
            'two', # empty line follows

            'three',
            ]
      assert_equal(['one', 'two', 'three'], mylist)
  END
  CheckScriptSuccess(lines)

  # check all lines from heredoc are kept
  lines =<< trim END
      # comment 1
      two
      # comment 3

      five
      # comment 6
  END
  assert_equal(['# comment 1', 'two', '# comment 3', '', 'five', '# comment 6'], lines)

  lines =<< trim END
    [{
      a: 0}]->string()->assert_equal("[{'a': 0}]")
  END
  CheckDefAndScriptSuccess(lines)
enddef

if has('channel')
  let someJob = test_null_job()

  def FuncWithError()
    echomsg g:someJob
  enddef

  func Test_convert_emsg_to_exception()
    try
      call FuncWithError()
    catch
      call assert_match('Vim:E908:', v:exception)
    endtry
  endfunc
endif

def Test_vim9script_mix()
  var lines =<< trim END
    if has(g:feature)
      " legacy script
      let g:legacy = 1
      finish
    endif
    vim9script
    g:legacy = 0
  END
  g:feature = 'eval'
  g:legacy = -1
  CheckScriptSuccess(lines)
  assert_equal(1, g:legacy)

  g:feature = 'noteval'
  g:legacy = -1
  CheckScriptSuccess(lines)
  assert_equal(0, g:legacy)
enddef

def Test_vim9script_fails()
  CheckScriptFailure(['scriptversion 2', 'vim9script'], 'E1039:')
  CheckScriptFailure(['vim9script', 'scriptversion 2'], 'E1040:')

  CheckScriptFailure(['vim9script', 'var str: string', 'str = 1234'], 'E1012:')
  CheckScriptFailure(['vim9script', 'const str = "asdf"', 'str = "xxx"'], 'E46:')

  assert_fails('vim9script', 'E1038:')
enddef

def Test_script_var_shadows_function()
  var lines =<< trim END
      vim9script
      def Func(): number
        return 123
      enddef
      var Func = 1
  END
  CheckScriptFailure(lines, 'E1041:', 5)
enddef

def Test_function_shadows_script_var()
  var lines =<< trim END
      vim9script
      var Func = 1
      def Func(): number
        return 123
      enddef
  END
  CheckScriptFailure(lines, 'E1041:', 3)
enddef

def Test_script_var_shadows_command()
  var lines =<< trim END
      var undo = 1
      undo = 2
      assert_equal(2, undo)
  END
  CheckDefAndScriptSuccess(lines)

  lines =<< trim END
      var undo = 1
      undo
  END
  CheckDefAndScriptFailure(lines, 'E1207:', 2)
enddef

def Test_vim9script_call_wrong_type()
  var lines =<< trim END
      vim9script
      var Time = 'localtime'
      Time()
  END
  CheckScriptFailure(lines, 'E1085:')
enddef

def Test_vim9script_reload_delfunc()
  var first_lines =<< trim END
    vim9script
    def FuncYes(): string
      return 'yes'
    enddef
  END
  var withno_lines =<< trim END
    def FuncNo(): string
      return 'no'
    enddef
    def g:DoCheck(no_exists: bool)
      assert_equal('yes', FuncYes())
      assert_equal('no', FuncNo())
    enddef
  END
  var nono_lines =<< trim END
    def g:DoCheck(no_exists: bool)
      assert_equal('yes', FuncYes())
      assert_fails('FuncNo()', 'E117:', '', 2, 'DoCheck')
    enddef
  END

  # FuncNo() is defined
  writefile(first_lines + withno_lines, 'Xreloaded.vim')
  source Xreloaded.vim
  g:DoCheck(true)

  # FuncNo() is not redefined
  writefile(first_lines + nono_lines, 'Xreloaded.vim')
  source Xreloaded.vim
  g:DoCheck(false)

  # FuncNo() is back
  writefile(first_lines + withno_lines, 'Xreloaded.vim')
  source Xreloaded.vim
  g:DoCheck(false)

  delete('Xreloaded.vim')
enddef

def Test_vim9script_reload_delvar()
  # write the script with a script-local variable
  var lines =<< trim END
    vim9script
    var name = 'string'
  END
  writefile(lines, 'XreloadVar.vim')
  source XreloadVar.vim

  # now write the script using the same variable locally - works
  lines =<< trim END
    vim9script
    def Func()
      var name = 'string'
    enddef
  END
  writefile(lines, 'XreloadVar.vim')
  source XreloadVar.vim

  delete('XreloadVar.vim')
enddef

def Test_func_redefine_error()
  var lines = [
        'vim9script',
        'def Func()',
        '  eval [][0]',
        'enddef',
        'Func()',
        ]
  writefile(lines, 'Xtestscript.vim')

  for count in range(3)
    try
      source Xtestscript.vim
    catch /E684/
      # function name should contain <SNR> every time
      assert_match('E684: list index out of range', v:exception)
      assert_match('function <SNR>\d\+_Func, line 1', v:throwpoint)
    endtry
  endfor

  delete('Xtestscript.vim')
enddef

def Test_func_redefine_fails()
  var lines =<< trim END
    vim9script
    def Func()
      echo 'one'
    enddef
    def Func()
      echo 'two'
    enddef
  END
  CheckScriptFailure(lines, 'E1073:')

  lines =<< trim END
    vim9script
    def Foo(): string
      return 'foo'
    enddef
    def Func()
      var  Foo = {-> 'lambda'}
    enddef
    defcompile
  END
  CheckScriptFailure(lines, 'E1073:')
enddef

def Test_fixed_size_list()
  # will be allocated as one piece of memory, check that changes work
  var l = [1, 2, 3, 4]
  l->remove(0)
  l->add(5)
  l->insert(99, 1)
  assert_equal([2, 99, 3, 4, 5], l)
enddef

def Test_no_insert_xit()
  CheckDefExecFailure(['a = 1'], 'E1100:')
  CheckDefExecFailure(['c = 1'], 'E1100:')
  CheckDefExecFailure(['i = 1'], 'E1100:')
  CheckDefExecFailure(['t = 1'], 'E1100:')
  CheckDefExecFailure(['x = 1'], 'E1100:')

  CheckScriptFailure(['vim9script', 'a = 1'], 'E488:')
  CheckScriptFailure(['vim9script', 'a'], 'E1100:')
  CheckScriptFailure(['vim9script', 'c = 1'], 'E488:')
  CheckScriptFailure(['vim9script', 'c'], 'E1100:')
  CheckScriptFailure(['vim9script', 'i = 1'], 'E488:')
  CheckScriptFailure(['vim9script', 'i'], 'E1100:')
  CheckScriptFailure(['vim9script', 'o = 1'], 'E1100:')
  CheckScriptFailure(['vim9script', 'o'], 'E1100:')
  CheckScriptFailure(['vim9script', 't'], 'E1100:')
  CheckScriptFailure(['vim9script', 't = 1'], 'E1100:')
  CheckScriptFailure(['vim9script', 'x = 1'], 'E1100:')
enddef

def IfElse(what: number): string
  var res = ''
  if what == 1
    res = "one"
  elseif what == 2
    res = "two"
  else
    res = "three"
  endif
  return res
enddef

def Test_if_elseif_else()
  assert_equal('one', IfElse(1))
  assert_equal('two', IfElse(2))
  assert_equal('three', IfElse(3))
enddef

def Test_if_elseif_else_fails()
  CheckDefFailure(['elseif true'], 'E582:')
  CheckDefFailure(['else'], 'E581:')
  CheckDefFailure(['endif'], 'E580:')
  CheckDefFailure(['if g:abool', 'elseif xxx'], 'E1001:')
  CheckDefFailure(['if true', 'echo 1'], 'E171:')

  var lines =<< trim END
      var s = ''
      if s = ''
      endif
  END
  CheckDefFailure(lines, 'E488:')

  lines =<< trim END
      var s = ''
      if s == ''
      elseif s = ''
      endif
  END
  CheckDefFailure(lines, 'E488:')
enddef

let g:bool_true = v:true
let g:bool_false = v:false

def Test_if_const_expr()
  var res = false
  if true ? true : false
    res = true
  endif
  assert_equal(true, res)

  g:glob = 2
  if false
    execute('g:glob = 3')
  endif
  assert_equal(2, g:glob)
  if true
    execute('g:glob = 3')
  endif
  assert_equal(3, g:glob)

  res = false
  if g:bool_true ? true : false
    res = true
  endif
  assert_equal(true, res)

  res = false
  if true ? g:bool_true : false
    res = true
  endif
  assert_equal(true, res)

  res = false
  if true ? true : g:bool_false
    res = true
  endif
  assert_equal(true, res)

  res = false
  if true ? false : true
    res = true
  endif
  assert_equal(false, res)

  res = false
  if false ? false : true
    res = true
  endif
  assert_equal(true, res)

  res = false
  if false ? true : false
    res = true
  endif
  assert_equal(false, res)

  res = false
  if has('xyz') ? true : false
    res = true
  endif
  assert_equal(false, res)

  res = false
  if true && true
    res = true
  endif
  assert_equal(true, res)

  res = false
  if true && false
    res = true
  endif
  assert_equal(false, res)

  res = false
  if g:bool_true && false
    res = true
  endif
  assert_equal(false, res)

  res = false
  if true && g:bool_false
    res = true
  endif
  assert_equal(false, res)

  res = false
  if false && false
    res = true
  endif
  assert_equal(false, res)

  res = false
  if true || false
    res = true
  endif
  assert_equal(true, res)

  res = false
  if g:bool_true || false
    res = true
  endif
  assert_equal(true, res)

  res = false
  if true || g:bool_false
    res = true
  endif
  assert_equal(true, res)

  res = false
  if false || false
    res = true
  endif
  assert_equal(false, res)

  # with constant "false" expression may be invalid so long as the syntax is OK
  if false | eval 1 + 2 | endif
  if false | eval burp + 234 | endif
  if false | echo burp 234 'asd' | endif
  if false
    burp
  endif

  # expression with line breaks skipped
  if false
      ('aaa'
      .. 'bbb'
      .. 'ccc'
      )->setline(1)
  endif
enddef

def Test_if_const_expr_fails()
  CheckDefFailure(['if "aaa" == "bbb'], 'E114:')
  CheckDefFailure(["if 'aaa' == 'bbb"], 'E115:')
  CheckDefFailure(["if has('aaa'"], 'E110:')
  CheckDefFailure(["if has('aaa') ? true false"], 'E109:')
enddef

def RunNested(i: number): number
  var x: number = 0
  if i % 2
    if 1
      # comment
    else
      # comment
    endif
    x += 1
  else
    x += 1000
  endif
  return x
enddef

def Test_nested_if()
  assert_equal(1, RunNested(1))
  assert_equal(1000, RunNested(2))
enddef

def Test_execute_cmd()
  # missing argument is ignored
  execute
  execute # comment

  new
  setline(1, 'default')
  execute 'setline(1, "execute-string")'
  assert_equal('execute-string', getline(1))

  execute "setline(1, 'execute-string')"
  assert_equal('execute-string', getline(1))

  var cmd1 = 'setline(1,'
  var cmd2 = '"execute-var")'
  execute cmd1 cmd2 # comment
  assert_equal('execute-var', getline(1))

  execute cmd1 cmd2 '|setline(1, "execute-var-string")'
  assert_equal('execute-var-string', getline(1))

  var cmd_first = 'call '
  var cmd_last = 'setline(1, "execute-var-var")'
  execute cmd_first .. cmd_last
  assert_equal('execute-var-var', getline(1))
  bwipe!

  var n = true
  execute 'echomsg' (n ? '"true"' : '"no"')
  assert_match('^true$', Screenline(&lines))

  echomsg [1, 2, 3] {a: 1, b: 2}
  assert_match('^\[1, 2, 3\] {''a'': 1, ''b'': 2}$', Screenline(&lines))

  CheckDefFailure(['execute xxx'], 'E1001:', 1)
  CheckDefExecFailure(['execute "tabnext " .. 8'], 'E475:', 1)
  CheckDefFailure(['execute "cmd"# comment'], 'E488:', 1)
enddef

def Test_execute_cmd_vimscript()
  # only checks line continuation
  var lines =<< trim END
      vim9script
      execute 'g:someVar'
                .. ' = ' ..
                   '28'
      assert_equal(28, g:someVar)
      unlet g:someVar
  END
  CheckScriptSuccess(lines)
enddef

def Test_echo_cmd()
  echo 'some' # comment
  echon 'thing'
  assert_match('^something$', Screenline(&lines))

  echo "some" # comment
  echon "thing"
  assert_match('^something$', Screenline(&lines))

  var str1 = 'some'
  var str2 = 'more'
  echo str1 str2
  assert_match('^some more$', Screenline(&lines))

  CheckDefFailure(['echo "xxx"# comment'], 'E488:')
enddef

def Test_echomsg_cmd()
  echomsg 'some' 'more' # comment
  assert_match('^some more$', Screenline(&lines))
  echo 'clear'
  :1messages
  assert_match('^some more$', Screenline(&lines))

  CheckDefFailure(['echomsg "xxx"# comment'], 'E488:')
enddef

def Test_echomsg_cmd_vimscript()
  # only checks line continuation
  var lines =<< trim END
      vim9script
      echomsg 'here'
                .. ' is ' ..
                   'a message'
      assert_match('^here is a message$', Screenline(&lines))
  END
  CheckScriptSuccess(lines)
enddef

def Test_echoerr_cmd()
  var local = 'local'
  try
    echoerr 'something' local 'wrong' # comment
  catch
    assert_match('something local wrong', v:exception)
  endtry
enddef

def Test_echoerr_cmd_vimscript()
  # only checks line continuation
  var lines =<< trim END
      vim9script
      try
        echoerr 'this'
                .. ' is ' ..
                   'wrong'
      catch
        assert_match('this is wrong', v:exception)
      endtry
  END
  CheckScriptSuccess(lines)
enddef

def Test_echoconsole_cmd()
  var local = 'local'
  echoconsole 'something' local # comment
  # output goes anywhere
enddef

def Test_for_outside_of_function()
  var lines =<< trim END
    vim9script
    new
    for var in range(0, 3)
      append(line('$'), var)
    endfor
    assert_equal(['', '0', '1', '2', '3'], getline(1, '$'))
    bwipe!

    var result = ''
    for i in [1, 2, 3]
      var loop = ' loop ' .. i
      result ..= loop
    endfor
    assert_equal(' loop 1 loop 2 loop 3', result)
  END
  writefile(lines, 'Xvim9for.vim')
  source Xvim9for.vim
  delete('Xvim9for.vim')
enddef

def Test_for_skipped_block()
  # test skipped blocks at outside of function
  var lines =<< trim END
    var result = []
    if true
      for n in [1, 2]
        result += [n]
      endfor
    else
      for n in [3, 4]
        result += [n]
      endfor
    endif
    assert_equal([1, 2], result)

    result = []
    if false
      for n in [1, 2]
        result += [n]
      endfor
    else
      for n in [3, 4]
        result += [n]
      endfor
    endif
    assert_equal([3, 4], result)
  END
  CheckDefAndScriptSuccess(lines)

  # test skipped blocks at inside of function
  lines =<< trim END
    def DefTrue()
      var result = []
      if true
        for n in [1, 2]
          result += [n]
        endfor
      else
        for n in [3, 4]
          result += [n]
        endfor
      endif
      assert_equal([1, 2], result)
    enddef
    DefTrue()

    def DefFalse()
      var result = []
      if false
        for n in [1, 2]
          result += [n]
        endfor
      else
        for n in [3, 4]
          result += [n]
        endfor
      endif
      assert_equal([3, 4], result)
    enddef
    DefFalse()
  END
  CheckDefAndScriptSuccess(lines)
enddef

def Test_for_loop()
  var lines =<< trim END
      var result = ''
      for cnt in range(7)
        if cnt == 4
          break
        endif
        if cnt == 2
          continue
        endif
        result ..= cnt .. '_'
      endfor
      assert_equal('0_1_3_', result)

      var concat = ''
      for str in eval('["one", "two"]')
        concat ..= str
      endfor
      assert_equal('onetwo', concat)

      var total = 0
      for nr in
          [1, 2, 3]
        total += nr
      endfor
      assert_equal(6, total)

      total = 0
      for nr
        in [1, 2, 3]
        total += nr
      endfor
      assert_equal(6, total)

      total = 0
      for nr
        in
        [1, 2, 3]
        total += nr
      endfor
      assert_equal(6, total)

      # with type
      total = 0
      for n: number in [1, 2, 3]
        total += n
      endfor
      assert_equal(6, total)

      var chars = ''
      for s: string in 'foobar'
        chars ..= s
      endfor
      assert_equal('foobar', chars)

      chars = ''
      for x: string in {a: 'a', b: 'b'}->values()
        chars ..= x
      endfor
      assert_equal('ab', chars)

      # unpack with type
      var res = ''
      for [n: number, s: string] in [[1, 'a'], [2, 'b']]
        res ..= n .. s
      endfor
      assert_equal('1a2b', res)

      # unpack with one var
      var reslist = []
      for [x] in [['aaa'], ['bbb']]
        reslist->add(x)
      endfor
      assert_equal(['aaa', 'bbb'], reslist)

      # loop over string
      res = ''
      for c in 'aéc̀d'
        res ..= c .. '-'
      endfor
      assert_equal('a-é-c̀-d-', res)

      res = ''
      for c in ''
        res ..= c .. '-'
      endfor
      assert_equal('', res)

      res = ''
      for c in test_null_string()
        res ..= c .. '-'
      endfor
      assert_equal('', res)

      var foo: list<dict<any>> = [
              {a: 'Cat'}
            ]
      for dd in foo
        dd.counter = 12
      endfor
      assert_equal([{a: 'Cat', counter: 12}], foo)

      reslist = []
      for _ in range(3)
        reslist->add('x')
      endfor
      assert_equal(['x', 'x', 'x'], reslist)
  END
  CheckDefAndScriptSuccess(lines)
enddef

def Test_for_loop_with_closure()
  var lines =<< trim END
      var flist: list<func>
      for i in range(5)
        var inloop = i
        flist[i] = () => inloop
      endfor
      for i in range(5)
        assert_equal(4, flist[i]())
      endfor
  END
  CheckDefAndScriptSuccess(lines)

  lines =<< trim END
      var flist: list<func>
      for i in range(5)
        var inloop = i
        flist[i] = () => {
              return inloop
            }
      endfor
      for i in range(5)
        assert_equal(4, flist[i]())
      endfor
  END
  CheckDefAndScriptSuccess(lines)
enddef

def Test_for_loop_fails()
  CheckDefAndScriptFailure(['for '], ['E1097:', 'E690:'])
  CheckDefAndScriptFailure(['for x'], ['E1097:', 'E690:'])
  CheckDefAndScriptFailure(['for x in'], ['E1097:', 'E15:'])
  CheckDefAndScriptFailure(['for # in range(5)'], 'E690:')
  CheckDefAndScriptFailure(['for i In range(5)'], 'E690:')
  CheckDefAndScriptFailure(['var x = 5', 'for x in range(5)', 'endfor'], ['E1017:', 'E1041:'])
  CheckScriptFailure(['vim9script', 'var x = 5', 'for x in range(5)', '# comment', 'endfor'], 'E1041:', 3)
  CheckScriptFailure(['def Func(arg: any)', 'for arg in range(5)', 'enddef', 'defcompile'], 'E1006:')
  delfunc! g:Func
  CheckDefFailure(['for i in xxx'], 'E1001:')
  CheckDefFailure(['endfor'], 'E588:')
  CheckDefFailure(['for i in range(3)', 'echo 3'], 'E170:')

  # wrong type detected at compile time
  CheckDefFailure(['for i in {a: 1}', 'echo 3', 'endfor'], 'E1177: For loop on dict not supported')

  # wrong type detected at runtime
  g:adict = {a: 1}
  CheckDefExecFailure(['for i in g:adict', 'echo 3', 'endfor'], 'E1177: For loop on dict not supported')
  unlet g:adict

  var lines =<< trim END
      var d: list<dict<any>> = [{a: 0}]
      for e in d
        e = {a: 0, b: ''}
      endfor
  END
  CheckDefAndScriptFailure(lines, ['E1018:', 'E46:'], 3)

  lines =<< trim END
      for nr: number in ['foo']
      endfor
  END
  CheckDefAndScriptFailure(lines, 'E1012: Type mismatch; expected number but got string', 1)

  lines =<< trim END
      for n : number in [1, 2]
        echo n
      endfor
  END
  CheckDefAndScriptFailure(lines, 'E1059:', 1)

  lines =<< trim END
      var d: dict<number> = {a: 1, b: 2}
      for [k: job, v: job] in d->items()
        echo k v
      endfor
  END
  CheckDefExecAndScriptFailure(lines, 'E1012: Type mismatch; expected job but got string', 2)

  lines =<< trim END
      var i = 0
      for i in [1, 2, 3]
        echo i
      endfor
  END
  CheckDefExecAndScriptFailure(lines, ['E1017:', 'E1041:'])

  lines =<< trim END
      var l = [0]
      for l[0] in [1, 2, 3]
        echo l[0]
      endfor
  END
  CheckDefExecAndScriptFailure(lines, ['E461:', 'E1017:'])

  lines =<< trim END
      var d = {x: 0}
      for d.x in [1, 2, 3]
        echo d.x
      endfor
  END
  CheckDefExecAndScriptFailure(lines, ['E461:', 'E1017:'])
enddef

def Test_for_loop_script_var()
  # cannot use s:var in a :def function
  CheckDefFailure(['for s:var in range(3)', 'echo 3'], 'E1254:')

  # can use s:var in Vim9 script, with or without s:
  var lines =<< trim END
    vim9script
    var total = 0
    for s:var in [1, 2, 3]
      total += s:var
    endfor
    assert_equal(6, total)

    total = 0
    for var in [1, 2, 3]
      total += var
    endfor
    assert_equal(6, total)
  END
enddef

def Test_for_loop_unpack()
  var lines =<< trim END
      var result = []
      for [v1, v2] in [[1, 2], [3, 4]]
        result->add(v1)
        result->add(v2)
      endfor
      assert_equal([1, 2, 3, 4], result)

      result = []
      for [v1, v2; v3] in [[1, 2], [3, 4, 5, 6]]
        result->add(v1)
        result->add(v2)
        result->add(v3)
      endfor
      assert_equal([1, 2, [], 3, 4, [5, 6]], result)

      result = []
      for [&ts, &sw] in [[1, 2], [3, 4]]
        result->add(&ts)
        result->add(&sw)
      endfor
      assert_equal([1, 2, 3, 4], result)

      var slist: list<string>
      for [$LOOPVAR, @r, v:errmsg] in [['a', 'b', 'c'], ['d', 'e', 'f']]
        slist->add($LOOPVAR)
        slist->add(@r)
        slist->add(v:errmsg)
      endfor
      assert_equal(['a', 'b', 'c', 'd', 'e', 'f'], slist)

      slist = []
      for [g:globalvar, b:bufvar, w:winvar, t:tabvar] in [['global', 'buf', 'win', 'tab'], ['1', '2', '3', '4']]
        slist->add(g:globalvar)
        slist->add(b:bufvar)
        slist->add(w:winvar)
        slist->add(t:tabvar)
      endfor
      assert_equal(['global', 'buf', 'win', 'tab', '1', '2', '3', '4'], slist)
      unlet! g:globalvar b:bufvar w:winvar t:tabvar

      var res = []
      for [_, n, _] in [[1, 2, 3], [4, 5, 6]]
        res->add(n)
      endfor
      assert_equal([2, 5], res)
  END
  CheckDefAndScriptSuccess(lines)

  lines =<< trim END
      for [v1, v2] in [[1, 2, 3], [3, 4]]
        echo v1 v2
      endfor
  END
  CheckDefExecFailure(lines, 'E710:', 1)

  lines =<< trim END
      for [v1, v2] in [[1], [3, 4]]
        echo v1 v2
      endfor
  END
  CheckDefExecFailure(lines, 'E711:', 1)

  lines =<< trim END
      for [v1, v1] in [[1, 2], [3, 4]]
        echo v1
      endfor
  END
  CheckDefExecFailure(lines, 'E1017:', 1)
enddef

def Test_for_loop_with_try_continue()
  var lines =<< trim END
      var looped = 0
      var cleanup = 0
      for i in range(3)
        looped += 1
        try
          eval [][0]
        catch
          continue
        finally
          cleanup += 1
        endtry
      endfor
      assert_equal(3, looped)
      assert_equal(3, cleanup)
  END
  CheckDefAndScriptSuccess(lines)
enddef

def Test_while_skipped_block()
  # test skipped blocks at outside of function
  var lines =<< trim END
    var result = []
    var n = 0
    if true
      n = 1
      while n < 3
        result += [n]
        n += 1
      endwhile
    else
      n = 3
      while n < 5
        result += [n]
        n += 1
      endwhile
    endif
    assert_equal([1, 2], result)

    result = []
    if false
      n = 1
      while n < 3
        result += [n]
        n += 1
      endwhile
    else
      n = 3
      while n < 5
        result += [n]
        n += 1
      endwhile
    endif
    assert_equal([3, 4], result)
  END
  CheckDefAndScriptSuccess(lines)

  # test skipped blocks at inside of function
  lines =<< trim END
    def DefTrue()
      var result = []
      var n = 0
      if true
        n = 1
        while n < 3
          result += [n]
          n += 1
        endwhile
      else
        n = 3
        while n < 5
          result += [n]
          n += 1
        endwhile
      endif
      assert_equal([1, 2], result)
    enddef
    DefTrue()

    def DefFalse()
      var result = []
      var n = 0
      if false
        n = 1
        while n < 3
          result += [n]
          n += 1
        endwhile
      else
        n = 3
        while n < 5
          result += [n]
          n += 1
        endwhile
      endif
      assert_equal([3, 4], result)
    enddef
    DefFalse()
  END
  CheckDefAndScriptSuccess(lines)
enddef

def Test_while_loop()
  var result = ''
  var cnt = 0
  while cnt < 555
    if cnt == 3
      break
    endif
    cnt += 1
    if cnt == 2
      continue
    endif
    result ..= cnt .. '_'
  endwhile
  assert_equal('1_3_', result)

  var s = ''
  while s == 'x' # {comment}
  endwhile
enddef

def Test_while_loop_in_script()
  var lines =<< trim END
      vim9script
      var result = ''
      var cnt = 0
      while cnt < 3
        var s = 'v' .. cnt
        result ..= s
        cnt += 1
      endwhile
      assert_equal('v0v1v2', result)
  END
  CheckScriptSuccess(lines)
enddef

def Test_while_loop_fails()
  CheckDefFailure(['while xxx'], 'E1001:')
  CheckDefFailure(['endwhile'], 'E588:')
  CheckDefFailure(['continue'], 'E586:')
  CheckDefFailure(['if true', 'continue'], 'E586:')
  CheckDefFailure(['break'], 'E587:')
  CheckDefFailure(['if true', 'break'], 'E587:')
  CheckDefFailure(['while 1', 'echo 3'], 'E170:')

  var lines =<< trim END
      var s = ''
      while s = ''
      endwhile
  END
  CheckDefFailure(lines, 'E488:')
enddef

def Test_interrupt_loop()
  var caught = false
  var x = 0
  try
    while 1
      x += 1
      if x == 100
        feedkeys("\<C-C>", 'Lt')
      endif
    endwhile
  catch
    caught = true
    assert_equal(100, x)
  endtry
  assert_true(caught, 'should have caught an exception')
  # consume the CTRL-C
  getchar(0)
enddef

def Test_automatic_line_continuation()
  var mylist = [
      'one',
      'two',
      'three',
      ] # comment
  assert_equal(['one', 'two', 'three'], mylist)

  var mydict = {
      ['one']: 1,
      ['two']: 2,
      ['three']:
          3,
      } # comment
  assert_equal({one: 1, two: 2, three: 3}, mydict)
  mydict = {
      one: 1,  # comment
      two:     # comment
           2,  # comment
      three: 3 # comment
      }
  assert_equal({one: 1, two: 2, three: 3}, mydict)
  mydict = {
      one: 1, 
      two: 
           2, 
      three: 3 
      }
  assert_equal({one: 1, two: 2, three: 3}, mydict)

  assert_equal(
        ['one', 'two', 'three'],
        split('one two three')
        )
enddef

def Test_vim9_comment()
  CheckScriptSuccess([
      'vim9script',
      '# something',
      '#something',
      '#{something',
      ])

  split Xfile
  CheckScriptSuccess([
      'vim9script',
      'edit #something',
      ])
  CheckScriptSuccess([
      'vim9script',
      'edit #{something',
      ])
  close

  CheckScriptFailure([
      'vim9script',
      ':# something',
      ], 'E488:')
  CheckScriptFailure([
      '# something',
      ], 'E488:')
  CheckScriptFailure([
      ':# something',
      ], 'E488:')

  { # block start
  } # block end
  CheckDefFailure([
      '{# comment',
      ], 'E488:')
  CheckDefFailure([
      '{',
      '}# comment',
      ], 'E488:')

  echo "yes" # comment
  CheckDefFailure([
      'echo "yes"# comment',
      ], 'E488:')
  CheckScriptSuccess([
      'vim9script',
      'echo "yes" # something',
      ])
  CheckScriptFailure([
      'vim9script',
      'echo "yes"# something',
      ], 'E121:')
  CheckScriptFailure([
      'vim9script',
      'echo# something',
      ], 'E1144:')
  CheckScriptFailure([
      'echo "yes" # something',
      ], 'E121:')

  exe "echo" # comment
  CheckDefFailure([
      'exe "echo"# comment',
      ], 'E488:')
  CheckScriptSuccess([
      'vim9script',
      'exe "echo" # something',
      ])
  CheckScriptFailure([
      'vim9script',
      'exe "echo"# something',
      ], 'E121:')
  CheckScriptFailure([
      'vim9script',
      'exe# something',
      ], 'E1144:')
  CheckScriptFailure([
      'exe "echo" # something',
      ], 'E121:')

  CheckDefFailure([
      'try# comment',
      '  echo "yes"',
      'catch',
      'endtry',
      ], 'E1144:')
  CheckScriptFailure([
      'vim9script',
      'try# comment',
      'echo "yes"',
      ], 'E1144:')
  CheckDefFailure([
      'try',
      '  throw#comment',
      'catch',
      'endtry',
      ], 'E1144:')
  CheckDefFailure([
      'try',
      '  throw "yes"#comment',
      'catch',
      'endtry',
      ], 'E488:')
  CheckDefFailure([
      'try',
      '  echo "yes"',
      'catch# comment',
      'endtry',
      ], 'E1144:')
  CheckScriptFailure([
      'vim9script',
      'try',
      '  echo "yes"',
      'catch# comment',
      'endtry',
      ], 'E1144:')
  CheckDefFailure([
      'try',
      '  echo "yes"',
      'catch /pat/# comment',
      'endtry',
      ], 'E488:')
  CheckDefFailure([
      'try',
      'echo "yes"',
      'catch',
      'endtry# comment',
      ], 'E1144:')
  CheckScriptFailure([
      'vim9script',
      'try',
      '  echo "yes"',
      'catch',
      'endtry# comment',
      ], 'E1144:')

  CheckScriptSuccess([
      'vim9script',
      'hi # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'hi# comment',
      ], 'E1144:')
  CheckScriptSuccess([
      'vim9script',
      'hi Search # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'hi Search# comment',
      ], 'E416:')
  CheckScriptSuccess([
      'vim9script',
      'hi link This Search # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'hi link This That# comment',
      ], 'E413:')
  CheckScriptSuccess([
      'vim9script',
      'hi clear This # comment',
      'hi clear # comment',
      ])
  # not tested, because it doesn't give an error but a warning:
  # hi clear This# comment',
  CheckScriptFailure([
      'vim9script',
      'hi clear# comment',
      ], 'E416:')

  CheckScriptSuccess([
      'vim9script',
      'hi Group term=bold',
      'match Group /todo/ # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'hi Group term=bold',
      'match Group /todo/# comment',
      ], 'E488:')
  CheckScriptSuccess([
      'vim9script',
      'match # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'match# comment',
      ], 'E1144:')
  CheckScriptSuccess([
      'vim9script',
      'match none # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'match none# comment',
      ], 'E475:')

  CheckScriptSuccess([
      'vim9script',
      'menutrans clear # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'menutrans clear# comment text',
      ], 'E474:')

  CheckScriptSuccess([
      'vim9script',
      'syntax clear # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax clear# comment text',
      ], 'E28:')
  CheckScriptSuccess([
      'vim9script',
      'syntax keyword Word some',
      'syntax clear Word # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax keyword Word some',
      'syntax clear Word# comment text',
      ], 'E28:')

  CheckScriptSuccess([
      'vim9script',
      'syntax list # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax list# comment text',
      ], 'E28:')

  CheckScriptSuccess([
      'vim9script',
      'syntax match Word /pat/ oneline # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax match Word /pat/ oneline# comment',
      ], 'E475:')

  CheckScriptSuccess([
      'vim9script',
      'syntax keyword Word word # comm[ent',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax keyword Word word# comm[ent',
      ], 'E789:')

  CheckScriptSuccess([
      'vim9script',
      'syntax match Word /pat/ # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax match Word /pat/# comment',
      ], 'E402:')

  CheckScriptSuccess([
      'vim9script',
      'syntax match Word /pat/ contains=Something # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax match Word /pat/ contains=Something# comment',
      ], 'E475:')
  CheckScriptFailure([
      'vim9script',
      'syntax match Word /pat/ contains= # comment',
      ], 'E406:')
  CheckScriptFailure([
      'vim9script',
      'syntax match Word /pat/ contains=# comment',
      ], 'E475:')

  CheckScriptSuccess([
      'vim9script',
      'syntax region Word start=/pat/ end=/pat/ # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax region Word start=/pat/ end=/pat/# comment',
      ], 'E402:')

  CheckScriptSuccess([
      'vim9script',
      'syntax sync # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax sync# comment',
      ], 'E404:')
  CheckScriptSuccess([
      'vim9script',
      'syntax sync ccomment # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax sync ccomment# comment',
      ], 'E404:')

  CheckScriptSuccess([
      'vim9script',
      'syntax cluster Some contains=Word # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'syntax cluster Some contains=Word# comment',
      ], 'E475:')

  CheckScriptSuccess([
      'vim9script',
      'command Echo echo # comment',
      'command Echo # comment',
      'delcommand Echo',
      ])
  CheckScriptFailure([
      'vim9script',
      'command Echo echo# comment',
      'Echo',
      ], 'E1144:')
  delcommand Echo

  var curdir = getcwd()
  CheckScriptSuccess([
      'command Echo cd " comment',
      'Echo',
      'delcommand Echo',
      ])
  CheckScriptSuccess([
      'vim9script',
      'command Echo cd # comment',
      'Echo',
      'delcommand Echo',
      ])
  CheckScriptFailure([
      'vim9script',
      'command Echo cd " comment',
      'Echo',
      ], 'E344:')
  delcommand Echo
  chdir(curdir)

  CheckScriptFailure([
      'vim9script',
      'command Echo# comment',
      ], 'E182:')
  CheckScriptFailure([
      'vim9script',
      'command Echo echo',
      'command Echo# comment',
      ], 'E182:')
  delcommand Echo

  CheckScriptSuccess([
      'vim9script',
      'function # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'function " comment',
      ], 'E129:')
  CheckScriptFailure([
      'vim9script',
      'function# comment',
      ], 'E1144:')
  CheckScriptSuccess([
      'vim9script',
      'function CheckScriptSuccess # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'function CheckScriptSuccess# comment',
      ], 'E488:')

  CheckScriptSuccess([
      'vim9script',
      'func g:DeleteMeA()',
      'endfunc',
      'delfunction g:DeleteMeA # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'func g:DeleteMeB()',
      'endfunc',
      'delfunction g:DeleteMeB# comment',
      ], 'E488:')

  CheckScriptSuccess([
      'vim9script',
      'call execute("ls") # comment',
      ])
  CheckScriptFailure([
      'vim9script',
      'call execute("ls")# comment',
      ], 'E488:')

  CheckScriptFailure([
      'def Test() " comment',
      'enddef',
      ], 'E488:')
  CheckScriptFailure([
      'vim9script',
      'def Test() " comment',
      'enddef',
      ], 'E488:')

  CheckScriptSuccess([
      'func Test() " comment',
      'endfunc',
      'delfunc Test',
      ])
  CheckScriptSuccess([
      'vim9script',
      'func Test() " comment',
      'endfunc',
      ])

  CheckScriptSuccess([
      'def Test() # comment',
      'enddef',
      ])
  CheckScriptFailure([
      'func Test() # comment',
      'endfunc',
      ], 'E488:')

  var lines =<< trim END
      vim9script
      syn region Text
      \ start='foo'
      #\ comment
      \ end='bar'
      syn region Text start='foo'
      #\ comment
      \ end='bar'
  END
  CheckScriptSuccess(lines)

  lines =<< trim END
      vim9script
      syn region Text
      \ start='foo'
      "\ comment
      \ end='bar'
  END
  CheckScriptFailure(lines, 'E399:')
enddef

def Test_vim9_comment_gui()
  CheckCanRunGui

  CheckScriptFailure([
      'vim9script',
      'gui#comment'
      ], 'E1144:')
  CheckScriptFailure([
      'vim9script',
      'gui -f#comment'
      ], 'E194:')
enddef

def Test_vim9_comment_not_compiled()
  au TabEnter *.vim g:entered = 1
  au TabEnter *.x g:entered = 2

  edit test.vim
  doautocmd TabEnter #comment
  assert_equal(1, g:entered)

  doautocmd TabEnter f.x
  assert_equal(2, g:entered)

  g:entered = 0
  doautocmd TabEnter f.x #comment
  assert_equal(2, g:entered)

  assert_fails('doautocmd Syntax#comment', 'E216:')

  au! TabEnter
  unlet g:entered

  CheckScriptSuccess([
      'vim9script',
      'g:var = 123',
      'b:var = 456',
      'w:var = 777',
      't:var = 888',
      'unlet g:var w:var # something',
      ])

  CheckScriptFailure([
      'vim9script',
      'let var = 123',
      ], 'E1126: Cannot use :let in Vim9 script')

  CheckScriptFailure([
      'vim9script',
      'var g:var = 123',
      ], 'E1016: Cannot declare a global variable:')

  CheckScriptFailure([
      'vim9script',
      'var b:var = 123',
      ], 'E1016: Cannot declare a buffer variable:')

  CheckScriptFailure([
      'vim9script',
      'var w:var = 123',
      ], 'E1016: Cannot declare a window variable:')

  CheckScriptFailure([
      'vim9script',
      'var t:var = 123',
      ], 'E1016: Cannot declare a tab variable:')

  CheckScriptFailure([
      'vim9script',
      'var v:version = 123',
      ], 'E1016: Cannot declare a v: variable:')

  CheckScriptFailure([
      'vim9script',
      'var $VARIABLE = "text"',
      ], 'E1016: Cannot declare an environment variable:')

  CheckScriptFailure([
      'vim9script',
      'g:var = 123',
      'unlet g:var# comment1',
      ], 'E108:')

  CheckScriptFailure([
      'let g:var = 123',
      'unlet g:var # something',
      ], 'E488:')

  CheckScriptSuccess([
      'vim9script',
      'if 1 # comment2',
      '  echo "yes"',
      'elseif 2 #comment',
      '  echo "no"',
      'endif',
      ])

  CheckScriptFailure([
      'vim9script',
      'if 1# comment3',
      '  echo "yes"',
      'endif',
      ], 'E488:')

  CheckScriptFailure([
      'vim9script',
      'if 0 # comment4',
      '  echo "yes"',
      'elseif 2#comment',
      '  echo "no"',
      'endif',
      ], 'E488:')

  CheckScriptSuccess([
      'vim9script',
      'var v = 1 # comment5',
      ])

  CheckScriptFailure([
      'vim9script',
      'var v = 1# comment6',
      ], 'E488:')

  CheckScriptSuccess([
      'vim9script',
      'new'
      'setline(1, ["# define pat", "last"])',
      ':$',
      'dsearch /pat/ #comment',
      'bwipe!',
      ])

  CheckScriptFailure([
      'vim9script',
      'new'
      'setline(1, ["# define pat", "last"])',
      ':$',
      'dsearch /pat/#comment',
      'bwipe!',
      ], 'E488:')

  CheckScriptFailure([
      'vim9script',
      'func! SomeFunc()',
      ], 'E477:')
enddef

def Test_finish()
  var lines =<< trim END
    vim9script
    g:res = 'one'
    if v:false | finish | endif
    g:res = 'two'
    finish
    g:res = 'three'
  END
  writefile(lines, 'Xfinished')
  source Xfinished
  assert_equal('two', g:res)

  unlet g:res
  delete('Xfinished')
enddef

def Test_forward_declaration()
  var lines =<< trim END
    vim9script
    def GetValue(): string
      return theVal
    enddef
    var theVal = 'something'
    g:initVal = GetValue()
    theVal = 'else'
    g:laterVal = GetValue()
  END
  writefile(lines, 'Xforward')
  source Xforward
  assert_equal('something', g:initVal)
  assert_equal('else', g:laterVal)

  unlet g:initVal
  unlet g:laterVal
  delete('Xforward')
enddef

def Test_declare_script_in_func()
  var lines =<< trim END
      vim9script
      func Declare()
        let s:local = 123
      endfunc
      Declare()
      assert_equal(123, local)

      var error: string
      try
        local = 'asdf'
      catch
        error = v:exception
      endtry
      assert_match('E1012: Type mismatch; expected number but got string', error)

      lockvar local
      try
        local = 999
      catch
        error = v:exception
      endtry
      assert_match('E741: Value is locked: local', error)
  END
  CheckScriptSuccess(lines)
enddef
        

func Test_vim9script_not_global()
  " check that items defined in Vim9 script are script-local, not global
  let vim9lines =<< trim END
    vim9script
    var name = 'local'
    func TheFunc()
      echo 'local'
    endfunc
    def DefFunc()
      echo 'local'
    enddef
  END
  call writefile(vim9lines, 'Xvim9script.vim')
  source Xvim9script.vim
  try
    echo g:var
    assert_report('did not fail')
  catch /E121:/
    " caught
  endtry
  try
    call TheFunc()
    assert_report('did not fail')
  catch /E117:/
    " caught
  endtry
  try
    call DefFunc()
    assert_report('did not fail')
  catch /E117:/
    " caught
  endtry

  call delete('Xvim9script.vim')
endfunc

def Test_vim9_copen()
  # this was giving an error for setting w:quickfix_title
  copen
  quit
enddef

def Test_script_var_in_autocmd()
  # using a script variable from an autocommand, defined in a :def function in a
  # legacy Vim script, cannot check the variable type.
  var lines =<< trim END
    let s:counter = 1
    def s:Func()
      au! CursorHold
      au CursorHold * s:counter += 1
    enddef
    call s:Func()
    doau CursorHold
    call assert_equal(2, s:counter)
    au! CursorHold
  END
  CheckScriptSuccess(lines)
enddef

def Test_error_in_autoload_script()
  var save_rtp = &rtp
  var dir = getcwd() .. '/Xruntime'
  &rtp = dir
  mkdir(dir .. '/autoload', 'p')

  var lines =<< trim END
      vim9script noclear
      def script#autoloaded()
      enddef
      def Broken()
        var x: any = ''
        eval x != 0
      enddef
      Broken()
  END
  writefile(lines, dir .. '/autoload/script.vim')

  lines =<< trim END
      vim9script
      def CallAutoloaded()
        script#autoloaded()
      enddef

      function Legacy()
        try
          call s:CallAutoloaded()
        catch
          call assert_match('E1030: Using a String as a Number', v:exception)
        endtry
      endfunction

      Legacy()
  END
  CheckScriptSuccess(lines)

  &rtp = save_rtp
  delete(dir, 'rf')
enddef

def Test_invalid_sid()
  assert_fails('func <SNR>1234_func', 'E123:')

  if RunVim([], ['wq! Xdidit'], '+"func <SNR>1_func"')
    assert_equal([], readfile('Xdidit'))
  endif
  delete('Xdidit')
enddef

def Test_restoring_cpo()
  writefile(['vim9script', 'set nocp'], 'Xsourced')
  writefile(['call writefile(["done"], "Xdone")', 'quit!'], 'Xclose')
  if RunVim([], [], '-u NONE +"set cpo+=a" -S Xsourced -S Xclose')
    assert_equal(['done'], readfile('Xdone'))
  endif
  delete('Xsourced')
  delete('Xclose')
  delete('Xdone')

  writefile(['vim9script', 'g:cpoval = &cpo'], 'XanotherScript')
  set cpo=aABceFsMny>
  edit XanotherScript
  so %
  assert_equal('aABceFsMny>', &cpo)
  assert_equal('aABceFs', g:cpoval)
  :1del
  setline(1, 'let g:cpoval = &cpo')
  w
  so %
  assert_equal('aABceFsMny>', &cpo)
  assert_equal('aABceFsMny>', g:cpoval)

  delete('XanotherScript')
  set cpo&vim
  unlet g:cpoval

  if has('unix')
    # 'cpo' is not restored in main vimrc
    var save_HOME = $HOME
    $HOME = getcwd() .. '/Xhome'
    mkdir('Xhome')
    var lines =<< trim END
        vim9script
        writefile(['before: ' .. &cpo], 'Xresult')
        set cpo+=M
        writefile(['after: ' .. &cpo], 'Xresult', 'a')
    END
    writefile(lines, 'Xhome/.vimrc')

    lines =<< trim END
        call writefile(['later: ' .. &cpo], 'Xresult', 'a')
    END
    writefile(lines, 'Xlegacy')

    lines =<< trim END
        vim9script
        call writefile(['vim9: ' .. &cpo], 'Xresult', 'a')
        qa
    END
    writefile(lines, 'Xvim9')

    var cmd = GetVimCommand() .. " -S Xlegacy -S Xvim9"
    cmd = substitute(cmd, '-u NONE', '', '')
    exe "silent !" .. cmd

    assert_equal([
        'before: aABceFs',
        'after: aABceFsM',
        'later: aABceFsM',
        'vim9: aABceFs'], readfile('Xresult'))

    $HOME = save_HOME
    delete('Xhome', 'rf')
    delete('Xlegacy')
    delete('Xvim9')
    delete('Xresult')
  endif
enddef

" Use :function so we can use Check commands
func Test_no_redraw_when_restoring_cpo()
  CheckScreendump
  CheckFeature timers

  let lines =<< trim END
    vim9script
    def script#func()
    enddef
  END
  call mkdir('Xdir/autoload', 'p')
  call writefile(lines, 'Xdir/autoload/script.vim')

  let lines =<< trim END
      vim9script
      set cpo+=M
      exe 'set rtp^=' .. getcwd() .. '/Xdir'
      au CmdlineEnter : ++once timer_start(0, (_) => script#func())
      setline(1, 'some text')
  END
  call writefile(lines, 'XTest_redraw_cpo')
  let buf = RunVimInTerminal('-S XTest_redraw_cpo', {'rows': 6})
  call term_sendkeys(buf, "V:")
  call VerifyScreenDump(buf, 'Test_vim9_no_redraw', {})

  " clean up
  call term_sendkeys(buf, "\<Esc>u")
  call StopVimInTerminal(buf)
  call delete('XTest_redraw_cpo')
  call delete('Xdir', 'rf')
endfunc


def Test_unset_any_variable()
  var lines =<< trim END
    var name: any
    assert_equal(0, name)
  END
  CheckDefAndScriptSuccess(lines)
enddef

func Test_define_func_at_command_line()
  CheckRunVimInTerminal

  " call indirectly to avoid compilation error for missing functions
  call Run_Test_define_func_at_command_line()
endfunc

def Run_Test_define_func_at_command_line()
  # run in a separate Vim instance to avoid the script context
  var lines =<< trim END
    func CheckAndQuit()
      call assert_fails('call Afunc()', 'E117: Unknown function: Bfunc')
      call writefile(['errors: ' .. string(v:errors)], 'Xdidcmd')
    endfunc
  END
  writefile([''], 'Xdidcmd')
  writefile(lines, 'XcallFunc')
  var buf = RunVimInTerminal('-S XcallFunc', {rows: 6})
  # define Afunc() on the command line
  term_sendkeys(buf, ":def Afunc()\<CR>Bfunc()\<CR>enddef\<CR>")
  term_sendkeys(buf, ":call CheckAndQuit()\<CR>")
  WaitForAssert(() => assert_equal(['errors: []'], readfile('Xdidcmd')))

  call StopVimInTerminal(buf)
  delete('XcallFunc')
  delete('Xdidcmd')
enddef

def Test_script_var_scope()
  var lines =<< trim END
      vim9script
      if true
        if true
          var one = 'one'
          echo one
        endif
        echo one
      endif
  END
  CheckScriptFailure(lines, 'E121:', 7)

  lines =<< trim END
      vim9script
      if true
        if false
          var one = 'one'
          echo one
        else
          var one = 'one'
          echo one
        endif
        echo one
      endif
  END
  CheckScriptFailure(lines, 'E121:', 10)

  lines =<< trim END
      vim9script
      while true
        var one = 'one'
        echo one
        break
      endwhile
      echo one
  END
  CheckScriptFailure(lines, 'E121:', 7)

  lines =<< trim END
      vim9script
      for i in range(1)
        var one = 'one'
        echo one
      endfor
      echo one
  END
  CheckScriptFailure(lines, 'E121:', 6)

  lines =<< trim END
      vim9script
      {
        var one = 'one'
        assert_equal('one', one)
      }
      assert_false(exists('one'))
      assert_false(exists('s:one'))
  END
  CheckScriptSuccess(lines)

  lines =<< trim END
      vim9script
      {
        var one = 'one'
        echo one
      }
      echo one
  END
  CheckScriptFailure(lines, 'E121:', 6)
enddef

def Test_catch_exception_in_callback()
  var lines =<< trim END
    vim9script
    def Callback(...l: list<any>)
      try
        var x: string
        var y: string
        # this error should be caught with CHECKLEN
        var sl = ['']
        [x, y] = sl
      catch
        g:caught = 'yes'
      endtry
    enddef
    popup_menu('popup', {callback: Callback})
    feedkeys("\r", 'xt')
  END
  CheckScriptSuccess(lines)

  unlet g:caught
enddef

def Test_no_unknown_error_after_error()
  if !has('unix') || !has('job')
    throw 'Skipped: not unix of missing +job feature'
  endif
  # FIXME: this check should not be needed
  if has('win32')
    throw 'Skipped: does not work on MS-Windows'
  endif
  var lines =<< trim END
      vim9script
      var source: list<number>
      def Out_cb(...l: list<any>)
          eval [][0]
      enddef
      def Exit_cb(...l: list<any>)
          sleep 1m
          source += l
      enddef
      var myjob = job_start('echo burp', {out_cb: Out_cb, exit_cb: Exit_cb, mode: 'raw'})
      while job_status(myjob) == 'run'
        sleep 10m
      endwhile
      # wait for Exit_cb() to be called
      sleep 200m
  END
  writefile(lines, 'Xdef')
  assert_fails('so Xdef', ['E684:', 'E1012:'])
  delete('Xdef')
enddef

def InvokeNormal()
  exe "norm! :m+1\r"
enddef

def Test_invoke_normal_in_visual_mode()
  xnoremap <F3> <Cmd>call <SID>InvokeNormal()<CR>
  new
  setline(1, ['aaa', 'bbb'])
  feedkeys("V\<F3>", 'xt')
  assert_equal(['bbb', 'aaa'], getline(1, 2))
  xunmap <F3>
enddef

def Test_white_space_after_command()
  var lines =<< trim END
    exit_cb: Func})
  END
  CheckDefAndScriptFailure(lines, 'E1144:', 1)

  lines =<< trim END
    e#
  END
  CheckDefAndScriptFailure(lines, 'E1144:', 1)
enddef

def Test_script_var_gone_when_sourced_twice()
  var lines =<< trim END
      vim9script
      if exists('g:guard')
        finish
      endif
      g:guard = 1
      var name = 'thename'
      def g:GetName(): string
        return name
      enddef
      def g:SetName(arg: string)
        name = arg
      enddef
  END
  writefile(lines, 'XscriptTwice.vim')
  so XscriptTwice.vim
  assert_equal('thename', g:GetName())
  g:SetName('newname')
  assert_equal('newname', g:GetName())
  so XscriptTwice.vim
  assert_fails('call g:GetName()', 'E1149:')
  assert_fails('call g:SetName("x")', 'E1149:')

  delfunc g:GetName
  delfunc g:SetName
  delete('XscriptTwice.vim')
  unlet g:guard
enddef

def Test_unsupported_commands()
  var lines =<< trim END
      ka
  END
  CheckDefFailure(lines, 'E476:')
  CheckScriptFailure(['vim9script'] + lines, 'E492:')

  lines =<< trim END
      :1ka
  END
  CheckDefFailure(lines, 'E476:')
  CheckScriptFailure(['vim9script'] + lines, 'E492:')

  lines =<< trim END
    t
  END
  CheckDefFailure(lines, 'E1100:')
  CheckScriptFailure(['vim9script'] + lines, 'E1100:')

  lines =<< trim END
    x
  END
  CheckDefFailure(lines, 'E1100:')
  CheckScriptFailure(['vim9script'] + lines, 'E1100:')

  lines =<< trim END
    xit
  END
  CheckDefFailure(lines, 'E1100:')
  CheckScriptFailure(['vim9script'] + lines, 'E1100:')
enddef

def Test_mapping_line_number()
  var lines =<< trim END
      vim9script
      def g:FuncA()
          # Some comment
          FuncB(0)
      enddef
          # Some comment
      def FuncB(
          # Some comment
          n: number
      )
          exe 'nno '
              # Some comment
              .. '<F3> a'
              .. 'b'
              .. 'c'
      enddef
  END
  CheckScriptSuccess(lines)
  var res = execute('verbose nmap <F3>')
  assert_match('No mapping found', res)

  g:FuncA()
  res = execute('verbose nmap <F3>')
  assert_match(' <F3> .* abc.*Last set from .*XScriptSuccess\d\+ line 11', res)

  nunmap <F3>
  delfunc g:FuncA
enddef

def Test_option_set()
  # legacy script allows for white space
  var lines =<< trim END
      set foldlevel  =11
      call assert_equal(11, &foldlevel)
  END
  CheckScriptSuccess(lines)

  set foldlevel
  set foldlevel=12
  assert_equal(12, &foldlevel)
  set foldlevel+=2
  assert_equal(14, &foldlevel)
  set foldlevel-=3
  assert_equal(11, &foldlevel)

  lines =<< trim END
      set foldlevel =1
  END
  CheckDefExecAndScriptFailure(lines, 'E1205: No white space allowed between option and: =1')

  lines =<< trim END
      set foldlevel +=1
  END
  CheckDefExecAndScriptFailure(lines, 'E1205: No white space allowed between option and: +=1')

  lines =<< trim END
      set foldlevel ^=1
  END
  CheckDefExecAndScriptFailure(lines, 'E1205: No white space allowed between option and: ^=1')

  lines =<< trim END
      set foldlevel -=1
  END
  CheckDefExecAndScriptFailure(lines, 'E1205: No white space allowed between option and: -=1')

  set foldlevel&
enddef

def Test_option_modifier()
  # legacy script allows for white space
  var lines =<< trim END
      set hlsearch &  hlsearch  !
      call assert_equal(1, &hlsearch)
  END
  CheckScriptSuccess(lines)

  set hlsearch
  set hlsearch!
  assert_equal(false, &hlsearch)

  set hlsearch
  set hlsearch&
  assert_equal(false, &hlsearch)

  lines =<< trim END
      set hlsearch &
  END
  CheckDefExecAndScriptFailure(lines, 'E1205: No white space allowed between option and: &')

  lines =<< trim END
      set hlsearch   !
  END
  CheckDefExecAndScriptFailure(lines, 'E1205: No white space allowed between option and: !')

  set hlsearch&
enddef

" This must be called last, it may cause following :def functions to fail
def Test_xxx_echoerr_line_number()
  var lines =<< trim END
      echoerr 'some'
         .. ' error'
         .. ' continued'
  END
  CheckDefExecAndScriptFailure(lines, 'some error continued', 1)
enddef

func Test_debug_with_lambda()
  CheckRunVimInTerminal

  " call indirectly to avoid compilation error for missing functions
  call Run_Test_debug_with_lambda()
endfunc

def Run_Test_debug_with_lambda()
  var lines =<< trim END
      vim9script
      def Func()
        var n = 0
        echo [0]->filter((_, v) => v == n)
      enddef
      breakadd func Func
      Func()
  END
  writefile(lines, 'XdebugFunc')
  var buf = RunVimInTerminal('-S XdebugFunc', {rows: 6, wait_for_ruler: 0})
  WaitForAssert(() => assert_match('^>', term_getline(buf, 6)))

  term_sendkeys(buf, "cont\<CR>")
  WaitForAssert(() => assert_match('\[0\]', term_getline(buf, 5)))

  StopVimInTerminal(buf)
  delete('XdebugFunc')
enddef

func Test_debug_running_out_of_lines()
  CheckRunVimInTerminal

  " call indirectly to avoid compilation error for missing functions
  call Run_Test_debug_running_out_of_lines()
endfunc

def Run_Test_debug_running_out_of_lines()
  var lines =<< trim END
      vim9script
      def Crash()
          #
          #
          #
          #
          #
          #
          #
          if true
              #
          endif
      enddef
      breakadd func Crash
      Crash()
  END
  writefile(lines, 'XdebugFunc')
  var buf = RunVimInTerminal('-S XdebugFunc', {rows: 6, wait_for_ruler: 0})
  WaitForAssert(() => assert_match('^>', term_getline(buf, 6)))

  term_sendkeys(buf, "next\<CR>")
  TermWait(buf)
  WaitForAssert(() => assert_match('^>', term_getline(buf, 6)))

  term_sendkeys(buf, "cont\<CR>")
  TermWait(buf)

  StopVimInTerminal(buf)
  delete('XdebugFunc')
enddef

def ProfiledWithLambda()
  var n = 3
  echo [[1, 2], [3, 4]]->filter((_, l) => l[0] == n)
enddef

def ProfiledNested()
  var x = 0
  def Nested(): any
      return x
  enddef
  Nested()
enddef

def ProfiledNestedProfiled()
  var x = 0
  def Nested(): any
      return x
  enddef
  Nested()
enddef

def Test_ambigous_command_error()
  var lines =<< trim END
      vim9script
      command CmdA echomsg 'CmdA'
      command CmdB echomsg 'CmdB'
      Cmd
  END
  CheckScriptFailure(lines, 'E464: Ambiguous use of user-defined command: Cmd', 4)

  lines =<< trim END
      vim9script
      def Func()
        Cmd
      enddef
      Func()
  END
  CheckScriptFailure(lines, 'E464: Ambiguous use of user-defined command: Cmd', 1)

  lines =<< trim END
      vim9script
      nnoremap <F3> <ScriptCmd>Cmd<CR>
      feedkeys("\<F3>", 'xt')
  END
  CheckScriptFailure(lines, 'E464: Ambiguous use of user-defined command: Cmd', 3)

  delcommand CmdA
  delcommand CmdB
  nunmap <F3>
enddef

" Execute this near the end, profiling doesn't stop until Vim exits.
" This only tests that it works, not the profiling output.
def Test_xx_profile_with_lambda()
  CheckFeature profile

  profile start Xprofile.log
  profile func ProfiledWithLambda
  ProfiledWithLambda()

  profile func ProfiledNested
  ProfiledNested()

  # Also profile the nested function.  Use a different function, although the
  # contents is the same, to make sure it was not already compiled.
  profile func *
  ProfiledNestedProfiled()

  profdel func *
  profile pause
enddef

" Keep this last, it messes up highlighting.
def Test_substitute_cmd()
  new
  setline(1, 'something')
  :substitute(some(other(
  assert_equal('otherthing', getline(1))
  bwipe!

  # also when the context is Vim9 script
  var lines =<< trim END
    vim9script
    new
    setline(1, 'something')
    :substitute(some(other(
    assert_equal('otherthing', getline(1))
    bwipe!
  END
  writefile(lines, 'Xvim9lines')
  source Xvim9lines

  delete('Xvim9lines')
enddef

" vim: ts=8 sw=2 sts=2 expandtab tw=80 fdm=marker
