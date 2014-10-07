# Let's define a common build environment first...
project_name = 'CPPExpressionParser' 
project_src = 'src'
include_path='E:\Claudio\VisualStudio\CrossPlatform\AmazonInterviewTraining\include'
common_env = Environment()
common_env.Append(CPPDEFINES={'VERSION': 1})
isWindows =  "win" in common_env['PLATFORM']
if isWindows:
  env = Environment( MSVC_USE_SCRIPT = "c:\\Program Files (x86)\\Microsoft Visual Studio 12.0\\VC\\bin\\vcvars32.bat")
  
# We define our debug build environment in a similar fashion...
debug_env = common_env.Clone()
debug_env.Append(CPPDEFINES=['DEBUG'])
debug_env.VariantDir('build/debug', project_src)

# Now that all build environment have been defined, let's iterate over
# them and invoke the lower level SConscript files.
for mode, env in dict(debug=debug_env).iteritems():
    env.SConscript('build/%s/SConscript' % mode, exports=['env', 'include_path'])


