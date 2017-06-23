<li>
	<a class="btn btn-outline" href="#" data-filter=".<?php print strtolower(preg_replace('/\s/', '', strip_tags($fields['name']->content))); ?>" onClick="ga('send', 'filter', 'restaurants', '<?php print strip_tags($fields['name']->content); ?>');">
		<?php print $fields['name']->content; ?>
	</a>
</li>